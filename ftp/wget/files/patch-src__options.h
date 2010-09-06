--- src/options.h	2010-05-08 19:56:15 +0000
+++ src/options.h	2010-07-28 19:22:22 +0000
@@ -242,6 +242,7 @@
   char *encoding_remote;
   char *locale;
 
+  bool trustservernames;
 #ifdef __VMS
   int ftp_stmlf;                /* Force Stream_LF format for binary FTP. */
 #endif /* def __VMS */

=== modified file 'src/retr.c'
