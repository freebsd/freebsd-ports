--- include/config.h.orig	2012-04-01 23:34:10.000000000 +0900
+++ include/config.h	2012-08-17 16:37:54.135991792 +0900
@@ -191,7 +191,7 @@
 /* #define COMPRESS "/usr/bin/compress" */	/* Lempel-Ziv compression */
 /* #define COMPRESS_EXTENSION ".Z"	*/	/* compress's extension */
 /* An example of one alternative you might want to use: */
-#define COMPRESS "/bin/gzip"	/* FSF gzip compression */
+#define COMPRESS "/usr/bin/gzip"	/* FSF gzip compression */
 #define COMPRESS_EXTENSION ".gz"		/* normal gzip extension */
 #endif
 
