$FreeBSD$

--- include/config.h.orig	Sat Dec 30 05:08:31 2006
+++ include/config.h	Fri Aug 17 23:09:31 2007
@@ -230,12 +230,12 @@
 
 #ifdef UNIX
 /* path and file name extension for compression program */
-# define COMPRESS "/usr/bin/compress" /* Lempel-Ziv compression */
-# define COMPRESS_EXTENSION ".Z"	     /* compress's extension */
+/* # define COMPRESS "/usr/bin/compress" */ /* Lempel-Ziv compression */
+/* # define COMPRESS_EXTENSION ".Z"	 */    /* compress's extension */
 
 /* An example of one alternative you might want to use: */
-/* # define COMPRESS "/usr/local/bin/gzip" */   /* FSF gzip compression */
-/* # define COMPRESS_EXTENSION ".gz" */	     /* normal gzip extension */
+# define COMPRESS "/usr/bin/gzip"   /* FSF gzip compression */
+# define COMPRESS_EXTENSION ".gz"	     /* normal gzip extension */
 
 /* # define COMPRESS "/usr/bin/bzip2"	*//* bzip2 compression */
 /* # define COMPRESS_EXTENSION ".bz2"	*//* bzip2 extension */
@@ -249,7 +249,7 @@
  *	a tar-like file, thus making a neater installation.  See *conf.h
  *	for detailed configuration.
  */
-/* #define DLB */             /* not supported on all platforms */
+#define DLB             /* not supported on all platforms */
 
 /*
  *	Defining INSURANCE slows down level changes, but allows games that
@@ -271,7 +271,7 @@
 #  ifdef __APPLE__
 #    define HACKDIR "nethackdir"      /* nethack directory */
 #  else
-#    define HACKDIR "."
+#    define HACKDIR "%%DATADIR%%"	/* nethack directory */
 #  endif
 # endif
 
