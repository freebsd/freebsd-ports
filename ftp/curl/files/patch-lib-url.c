Description: Different handling of signals and threads.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-12-18

--- lib/url.c.orig	2019-05-21 17:57:39 UTC
+++ lib/url.c
@@ -439,7 +439,7 @@ CURLcode Curl_init_userdefined(struct Cu
 
   set->httpreq = HTTPREQ_GET; /* Default HTTP request */
   set->rtspreq = RTSPREQ_OPTIONS; /* Default RTSP request */
-#ifndef CURL_DISABLE_FILE
+#ifndef CURL_DISABLE_FTP
   set->ftp_use_epsv = TRUE;   /* FTP defaults to EPSV operations */
   set->ftp_use_eprt = TRUE;   /* FTP defaults to EPRT operations */
   set->ftp_use_pret = FALSE;  /* mainly useful for drftpd servers */
@@ -552,6 +552,10 @@ CURLcode Curl_init_userdefined(struct Cu
     CURL_HTTP_VERSION_1_1
 #endif
     ;
+#if defined(__FreeBSD_version)
+  /* different handling of signals and threads */
+  set->no_signal = TRUE;
+#endif
   Curl_http2_init_userset(set);
   return result;
 }
