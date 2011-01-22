--- include/config.h.orig	2010-10-10 21:46:00.000000000 +0900
+++ include/config.h	2011-01-22 01:34:41.205152954 +0900
@@ -188,7 +188,7 @@
 /* #define COMPRESS "/usr/bin/compress" */	/* Lempel-Ziv compression */
 /* #define COMPRESS_EXTENSION ".Z"	*/	/* compress's extension */
 /* An example of one alternative you might want to use: */
-#define COMPRESS "/bin/gzip"	/* FSF gzip compression */
+#define COMPRESS "/usr/bin/gzip"	/* FSF gzip compression */
 #define COMPRESS_EXTENSION ".gz"		/* normal gzip extension */
 #endif
 
@@ -202,7 +202,7 @@
  *	a tar-like file, thus making a neater installation.  See *conf.h
  *	for detailed configuration.
  */
-/* #define DLB */	/* not supported on all platforms */
+#define DLB	/* not supported on all platforms */
 
 /*
  *	Defining INSURANCE slows down level changes, but allows games that
@@ -221,7 +221,7 @@
  * otherwise it will be the current directory.
  */
 # ifndef HACKDIR
-#  define HACKDIR "/usr/games/lib/unnethackdir"
+#  define HACKDIR "%%DATADIR%%"
 # endif
 
 /*
