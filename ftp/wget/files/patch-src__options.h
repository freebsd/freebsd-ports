--- src/options.h.orig	2014-10-27 09:15:33.000000000 +0100
+++ src/options.h	2014-11-10 10:39:21.587093055 +0100
@@ -220,7 +220,6 @@
   char *ca_cert;                /* CA certificate file to use */
 
   char *random_file;            /* file with random data to seed the PRNG */
-  char *egd_file;               /* file name of the egd daemon socket */
   bool https_only;              /* whether to follow HTTPS only */
 #endif /* HAVE_SSL */
 
