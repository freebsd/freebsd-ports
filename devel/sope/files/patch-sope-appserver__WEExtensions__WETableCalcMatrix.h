--- sope-appserver/WEExtensions/WETableCalcMatrix.h.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/WEExtensions/WETableCalcMatrix.h
@@ -66,7 +66,7 @@
   BOOL           rowCheck;
 }
 
-- (id)initWithSize:(unsigned)_width:(unsigned)_height;
+- (id)initWithSize:(unsigned)_width :(unsigned)_height;
 
 /* static accessors */
 
@@ -111,7 +111,7 @@
 
 - (BOOL)tableCalcMatrix:(WETableCalcMatrix *)_matrix
   shouldPlaceObject:(id)_object
-  atPosition:(unsigned)_x:(unsigned)_y;
+  atPosition:(unsigned)_x :(unsigned)_y;
 
 /* define if you want to create own span objects */
 
