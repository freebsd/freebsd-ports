--- ddd/ScrolleGEP.h.orig	2009-02-11 18:25:07.000000000 +0100
+++ ddd/ScrolleGEP.h	2016-04-04 21:29:40.085223000 +0200
@@ -31,13 +31,9 @@
 #include <Xm/Xm.h>
 
 // Superclasses
-#define new new_w
-#define class class_w
 #include <Xm/XmP.h>
 #include <X11/CoreP.h>
 #include <Xm/ScrolledWP.h>
-#undef new
-#undef class
 
 #ifdef MAX
 #undef MAX			// <Xm/XmP.h> on HP-UX defines this
