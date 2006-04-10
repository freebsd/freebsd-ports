--- src/Fl_Cursor_Shape.cxx.orig	Mon Apr 10 11:16:04 2006
+++ src/Fl_Cursor_Shape.cxx	Mon Apr 10 11:16:18 2006
@@ -53,7 +53,7 @@
 # include <malloc.h>
 #elif defined(__APPLE__)
 #else
-# include <malloc.h>
+# include <stdlib.h>
 # include <string.h>
 #endif
 
