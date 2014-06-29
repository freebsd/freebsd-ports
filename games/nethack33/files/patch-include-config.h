$FreeBSD$

--- include/config.h.orig	Sat Jul 22 10:13:51 2000
+++ include/config.h	Sat May 18 06:27:54 2002
@@ -110,7 +110,7 @@
  * would allow:
  *  xpmtoppm <x11tiles.xpm | pnmscale 1.25 | ppmquant 90 >x11tiles_big.xpm
  */
-/* # define USE_XPM */		/* Disable if you do not have the XPM library */
+# define USE_XPM 		/* Disable if you do not have the XPM library */
 # ifdef USE_XPM
 #  define GRAPHIC_TOMBSTONE	/* Use graphical tombstone (rip.xpm) */
 # endif
@@ -151,11 +151,11 @@
 
 #ifdef UNIX
 /* path and file name extension for compression program */
-#define COMPRESS "/usr/bin/compress"	/* Lempel-Ziv compression */
-#define COMPRESS_EXTENSION ".Z"		/* compress's extension */
+/* #define COMPRESS "/usr/bin/compress"*/	/* Lempel-Ziv compression */
+/* #define COMPRESS_EXTENSION ".Z"	*/	/* compress's extension */
 /* An example of one alternative you might want to use: */
-/* #define COMPRESS "/usr/local/bin/gzip" */	/* FSF gzip compression */
-/* #define COMPRESS_EXTENSION ".gz" */		/* normal gzip extension */
+#define COMPRESS "/usr/bin/gzip"	 	/* FSF gzip compression */
+#define COMPRESS_EXTENSION ".gz" 		/* normal gzip extension */
 #endif
 
 #ifndef COMPRESS
@@ -186,7 +186,7 @@
  * otherwise it will be the current directory.
  */
 # ifndef HACKDIR
-#  define HACKDIR "/usr/games/lib/nethackdir"	/* nethack directory */
+#  define HACKDIR "%%HACKDIR%%"	/* nethack directory */
 # endif
 
 /*
