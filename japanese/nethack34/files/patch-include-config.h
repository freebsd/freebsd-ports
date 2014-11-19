--- include/config.h.orig	2014-10-18 21:39:21.000000000 +0900
+++ include/config.h	2014-10-18 21:48:34.000000000 +0900
@@ -133,7 +133,7 @@
  * would allow:
  *  xpmtoppm <x11tiles.xpm | pnmscale 1.25 | ppmquant 90 >x11tiles_big.xpm
  */
-/*# define USE_XPM*/		/* Disable if you do not have the XPM library */
+# define USE_XPM		/* Disable if you do not have the XPM library */
 # ifdef USE_XPM
 #  define GRAPHIC_TOMBSTONE	/* Use graphical tombstone (rip.xpm) */
 #  define X11LARGETILE		/* Large tile for X11 */
@@ -219,7 +219,7 @@
  * otherwise it will be the current directory.
  */
 # ifndef HACKDIR
-#  define HACKDIR "/usr/games/lib/jnethackdir"
+#  define HACKDIR "%%HACKDIR%%"
 # endif
 
 /*
