--- ddd/SwallowerP.h.orig	2009-02-11 18:25:07.000000000 +0100
+++ ddd/SwallowerP.h	2016-04-04 21:29:40.084451000 +0200
@@ -35,11 +35,7 @@
 
 // Superclasses
 extern "C" {
-#define new new_w
-#define class class_w
 #include <X11/CoreP.h>
-#undef new
-#undef class
 }
 
 // The Swallower class record
