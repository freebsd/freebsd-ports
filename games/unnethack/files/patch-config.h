--- include/config.h.good	Wed Nov 22 23:18:52 2000
+++ include/config.h	Wed Nov 22 23:29:22 2000
@@ -176,12 +176,12 @@
 
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
@@ -195,7 +195,7 @@
  *	a tar-like file, thus making a neater installation.  See *conf.h
  *	for detailed configuration.
  */
-/* #define DLB */             /* not supported on all platforms */
+#define DLB             /* not supported on all platforms */
 
 /*
  *	Defining INSURANCE slows down level changes, but allows games that
@@ -214,7 +214,7 @@
  * otherwise it will be the current directory.
  */
 # ifndef HACKDIR
-#  define HACKDIR "."	/* nethack directory */
+#  define HACKDIR "/usr/local/share/slashem-tty"	/* nethack directory */
 # endif
 
 /*
