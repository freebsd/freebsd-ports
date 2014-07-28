
$FreeBSD$

--- columns.cc.orig	2000-03-17 04:52:55.000000000 +0400
+++ columns.cc	2013-06-13 15:21:46.472644056 +0400
@@ -22,10 +22,12 @@
 #include <stdarg.h>
 #include <stdio.h>
 #include <string.h>
+#ifndef __STDC__
 #include <malloc.h>
+#endif
 #include <stdlib.h>
 #include <time.h>
-#include <SDL/SDL.h>
+#include <SDL.h>
 
 #define HIGHSCORE_X 10
 #define HIGHSCORE_Y 30
@@ -1365,6 +1367,7 @@ void eval_args(int argc, char **argv)
     }
 }
 
+int
 main (int argc, char **argv)
 {
     eval_args(argc, argv);
