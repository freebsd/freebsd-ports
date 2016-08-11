--- ddd/GraphEditP.h.orig	2009-02-11 18:25:06.000000000 +0100
+++ ddd/GraphEditP.h	2016-04-04 21:29:40.084971000 +0200
@@ -30,15 +30,11 @@
 
 // Superclasses
 extern "C" {
-#define new new_w
-#define class class_w
 #include <X11/CoreP.h>
 #include <Xm/XmP.h>
 #if XmVersion >= 1002
 #include <Xm/PrimitiveP.h>
 #endif
-#undef new
-#undef class
 }
 
 // This class
