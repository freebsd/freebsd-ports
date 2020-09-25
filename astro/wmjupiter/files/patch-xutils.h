--- xutils.h.orig	2015-12-06 02:51:22 UTC
+++ xutils.h
@@ -18,12 +18,12 @@ typedef struct {
 /*
  *   Global variable
  */
-Display		*display;
-Window          Root;
-Window          iconwin, win;
-int             screen; 
-int             DisplayDepth;
-GC NormalGC;
+extern Display	*display;
+extern Window	Root;
+extern Window	iconwin, win;
+extern int	screen; 
+extern int	DisplayDepth;
+extern GC	NormalGC;
 
 
 
