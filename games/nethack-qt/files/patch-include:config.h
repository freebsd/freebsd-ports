--- include/config.h.orig	Sat Jul 22 10:13:51 2000
+++ include/config.h	Sat Aug 11 10:09:12 2001
@@ -44,7 +44,7 @@
  */
 #define TTY_GRAPHICS	/* good old tty based graphics */
 /* #define X11_GRAPHICS */	/* X11 interface */
-/* #define QT_GRAPHICS */	/* Qt interface */
+#define QT_GRAPHICS	/* Qt interface */
 /* #define GNOME_GRAPHICS */	/* Gnome interface */
 
 /*
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
+#  define HACKDIR "%%PREFIX%%/lib/nethack"	/* nethack directory */
 # endif
 
 /*
