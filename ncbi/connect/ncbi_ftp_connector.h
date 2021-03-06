#ifndef CONNECT___NCBI_FTP_CONNECTOR__H
#define CONNECT___NCBI_FTP_CONNECTOR__H

/* $Id: ncbi_ftp_connector.h,v 1.3 2008/10/16 18:55:44 kazimird Exp $
 * ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 * Author:  Anton Lavrentiev
 *
 * File Description:
 *   FTP CONNECTOR
 *
 *   See <connect/ncbi_connector.h> for the detailed specification of
 *   the connector's methods and structures.
 *
 */

#include <connect/ncbi_buffer.h>
#include <connect/ncbi_connector.h>


/** @addtogroup Connectors
 *
 * @{
 */


#ifdef __cplusplus
extern "C" {
#endif


typedef enum {
    fFCDC_LogControl = 1,
    fFCDC_LogData    = 2,
    fFCDC_LogAll     = fFCDC_LogControl | fFCDC_LogData
} EFCDC_Flags;
typedef unsigned int TFCDC_Flags;

typedef enum { /* DEPRECATED -- DON'T USE */
    eFCDC_LogControl = fFCDC_LogControl,
    eFCDC_LogData    = fFCDC_LogData,
    eFCDC_LogAll     = fFCDC_LogAll
} EFCDC_OldFlags;


/* Create new CONNECTOR structure to handle ftp download transfer.
 * Return NULL on error.
 */
extern NCBI_XCONNECT_EXPORT CONNECTOR FTP_CreateDownloadConnector
(const char*    host,     /* hostname, required                             */
 unsigned short port,     /* port #, 21 [standard] if 0 passed here         */
 const char*    user,     /* username, "ftp" [==anonymous] by default       */
 const char*    pass,     /* password, "none" by default                    */
 const char*    path,     /* initial directory to chdir to on open          */
 TFCDC_Flags    flag      /* mostly for logging socket data [optional]      */
);


#ifdef __cplusplus
}  /* extern "C" */
#endif


/* @} */

#endif /* CONNECT___NCBI_FTP_CONNECTOR__H */
