--- lib/ftplib.h.orig	2021-08-17 12:17:32 UTC
+++ lib/ftplib.h
@@ -55,7 +55,7 @@ extern "C" {
 typedef struct NetBuf netbuf;
 
 /* v1 compatibility stuff */
-netbuf *DefaultNetbuf;
+extern netbuf *DefaultNetbuf;
 
 #define ftplib_lastresp FtpLastResponse(DefaultNetbuf)
 #define ftpInit FtpInit
