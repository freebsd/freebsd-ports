$FreeBSD$

--- include/config.h.orig	Tue Dec 10 13:20:07 1996
+++ include/config.h	Sat Apr 10 01:01:28 2004
@@ -211,7 +211,7 @@
  * Some combinations make no sense.  See the installation document.
  */
 #define TTY_GRAPHICS	/* good old tty based graphics */
-/* #define X11_GRAPHICS	/* X11 interface */
+#define X11_GRAPHICS	/* X11 interface */
 
 /*
  * Define the default window system.  This should be one that is compiled
@@ -256,7 +256,7 @@
  * would allow:
  *  xpmtoppm <x11tiles.xpm | pnmscale 1.25 | ppmquant 90 >x11tiles_big.xpm
  */
-/* # define USE_XPM		/* Disable if you do not have the XPM library */
+# define USE_XPM		/* Disable if you do not have the XPM library */
 # ifdef USE_XPM
 #  define GRAPHIC_TOMBSTONE	/* Use graphical tombstone (rip.xpm) */
 # endif
@@ -296,12 +296,12 @@
 
 #ifdef UNIX
 /* path and file name extension for compression program */
-# define COMPRESS "/usr/ucb/compress"	     /* Lempel-Ziv compression */
-# define COMPRESS_EXTENSION ".Z"	     /* compress's extension */
+/* # define COMPRESS "/usr/ucb/compress"     /* Lempel-Ziv compression */
+/* # define COMPRESS_EXTENSION ".Z"	     /* compress's extension */
 
 /* An example of one alternative you might want to use: */
-/* # define COMPRESS "/usr/local/bin/gzip"   /* FSF gzip compression */
-/* # define COMPRESS_EXTENSION ".gz"	     /* normal gzip extension */
+# define COMPRESS "/usr/bin/gzip"   /* FSF gzip compression */
+# define COMPRESS_EXTENSION ".gz"	     /* normal gzip extension */
 #endif
 #ifndef COMPRESS
 # define INTERNAL_COMP	/* control use of NetHack's compression routines */
@@ -331,7 +331,7 @@
  * otherwise it will be the current directory.
  */
 # ifndef HACKDIR
-#  define HACKDIR "/usr/games/lib/nethackdir"	/* nethack directory */
+#  define HACKDIR "%%HACKDIR%%"	/* nethack directory */
 # endif
 
 /*
