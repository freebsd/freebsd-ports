--- defs.h	Fri Jan  1 03:08:19 1999
+++ /home/andy/tmp/wrk/defs.h	Fri May 14 20:51:11 1999
@@ -45,7 +45,9 @@
    This might usually be "/usr/games/lib/omegalib/", for unix,
    or something like "c:\\games\\omega\\omegalib\\" for msdos */
 
+#ifndef OMEGALIB
 #define OMEGALIB "./lib/"
+#endif
 
 /* Comment the following line out if you want users to be able to override */
 /* the OMEGALIB define, above, by setting the environment variable OMEGALIB */
@@ -570,7 +572,11 @@
 /* WDT: thank goodness for that lack of implementation. */
 
 #else
+#ifdef __FreeBSD__
+#include <ncurses.h>
+#else
 #include <curses.h>
+#endif
 
 #define COL_FG_BLINK A_BLINK
 
