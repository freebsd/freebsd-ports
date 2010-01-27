$FreeBSD$

--- include/config.h.orig	2010-01-10 23:51:18.000000000 +0900
+++ include/config.h	2010-01-19 13:36:18.734207870 +0900
@@ -178,11 +178,11 @@
 #ifndef AUTOCONF
 #ifdef UNIX
 /* path and file name extension for compression program */
-#define COMPRESS "/usr/bin/compress"	/* Lempel-Ziv compression */
-#define COMPRESS_EXTENSION ".Z"		/* compress's extension */
+/* #define COMPRESS "/usr/bin/compress" */	/* Lempel-Ziv compression */
+/* #define COMPRESS_EXTENSION ".Z" */		/* compress's extension */
 /* An example of one alternative you might want to use: */
-/* #define COMPRESS "/usr/local/bin/gzip" */	/* FSF gzip compression */
-/* #define COMPRESS_EXTENSION ".gz" */		/* normal gzip extension */
+#define COMPRESS "/usr/bin/gzip"	/* FSF gzip compression */
+#define COMPRESS_EXTENSION ".gz"		/* normal gzip extension */
 #endif
 
 #ifndef COMPRESS
@@ -195,7 +195,7 @@
  *	a tar-like file, thus making a neater installation.  See *conf.h
  *	for detailed configuration.
  */
-/* #define DLB */	/* not supported on all platforms */
+#define DLB	/* not supported on all platforms */
 
 /*
  *	Defining INSURANCE slows down level changes, but allows games that
@@ -214,7 +214,7 @@
  * otherwise it will be the current directory.
  */
 # ifndef HACKDIR
-#  define HACKDIR "/usr/games/lib/unnethackdir"
+#  define HACKDIR "%%DATADIR%%"
 # endif
 
 /*
