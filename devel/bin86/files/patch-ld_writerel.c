--- ld/writerel.c.orig	Wed Apr 23 21:05:51 1997
+++ ld/writerel.c	Thu Oct 19 17:01:59 2000
@@ -9,7 +9,7 @@
  *       an as86 object file.
  */
 
-#ifdef BUGCOMPAT
+#if 0
 #define A_OUT_INCL		"rel_aout.h"
 #define BSD_A_OUT		1
 #define FILEHEADERLENGTH	32
