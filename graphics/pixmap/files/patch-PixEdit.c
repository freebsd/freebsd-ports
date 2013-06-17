--- PixEdit.c.orig
+++ PixEdit.c
@@ -59,6 +59,7 @@
 
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <X11/Intrinsic.h>
 #include <X11/Xos.h>
 #include <X11/Xfuncs.h>
@@ -1938,7 +1939,7 @@
 
 
 
-void main(argc, argv)
+int main(argc, argv)
     int    argc;
     char  *argv[];
 {
@@ -2281,4 +2282,5 @@
 
     XtRealizeWidget(top_widget);
     XtAppMainLoop(pixmap_context);
+    return 0;
 }
