--- ddd/PannedGEP.h.orig	2009-02-11 18:25:06.000000000 +0100
+++ ddd/PannedGEP.h	2016-04-04 21:29:40.083754000 +0200
@@ -32,15 +32,11 @@
 #include <Xm/Xm.h>
 
 // Superclasses
-#define new new_w
-#define class class_w
 extern "C" {
 #include <X11/IntrinsicP.h>
 #include <X11/CompositeP.h>
 #include <X11/Xaw/PortholeP.h>
 }
-#undef new
-#undef class
 
 // This class
 #include "PannedGE.h"
