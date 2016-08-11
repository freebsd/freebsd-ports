--- ddd/converters.C.orig	2009-02-11 18:25:07.000000000 +0100
+++ ddd/converters.C	2016-04-04 21:29:40.084242000 +0200
@@ -56,9 +56,6 @@ char converters_rcsid[] = 
 
 #include <Xm/Xm.h>
 
-#define new new_w
-#define class class_w
-
 #if XmVersion < 1002
 #include <Xm/bitmaps.h>
 #else
@@ -101,9 +98,6 @@ extern "C" {
 #include <Xm/PrimitiveP.h>
 #endif
 
-#undef new
-#undef class
-
 #include "converters.h"
 #include "MString.h"
 
