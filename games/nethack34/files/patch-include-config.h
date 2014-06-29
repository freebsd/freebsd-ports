--- include/config.h.orig	Mon Dec  8 00:39:13 2003
+++ include/config.h	Sun Sep  3 12:17:19 2006
@@ -85,9 +85,6 @@
 #ifdef QT_GRAPHICS
 # define DEFAULT_WC_TILED_MAP   /* Default to tiles if users doesn't say wc_ascii_map */
 # define USER_SOUNDS		/* Use sounds */
-# ifndef __APPLE__
-#  define USER_SOUNDS_REGEX
-# endif
 # define USE_XPM		/* Use XPM format for images (required) */
 # define GRAPHIC_TOMBSTONE	/* Use graphical tombstone (rip.ppm) */
 # ifndef DEFAULT_WINDOW_SYS
@@ -126,7 +123,7 @@
  * would allow:
  *  xpmtoppm <x11tiles.xpm | pnmscale 1.25 | ppmquant 90 >x11tiles_big.xpm
  */
-/* # define USE_XPM */		/* Disable if you do not have the XPM library */
+# define USE_XPM		/* Disable if you do not have the XPM library */
 # ifdef USE_XPM
 #  define GRAPHIC_TOMBSTONE	/* Use graphical tombstone (rip.xpm) */
 # endif
@@ -169,11 +166,11 @@
 
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
@@ -204,7 +201,7 @@
  * otherwise it will be the current directory.
  */
 # ifndef HACKDIR
-#  define HACKDIR "/usr/games/lib/nethackdir"
+#  define HACKDIR "%%HACKDIR%%"
 # endif
 
 /*
