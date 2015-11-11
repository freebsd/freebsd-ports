--- sope-appserver/WEExtensions/WETableMatrix.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/WEExtensions/WETableMatrix.m
@@ -139,7 +139,7 @@ static NSNumber *numForUInt(unsigned int
 
 - (BOOL)tableCalcMatrix:(WETableCalcMatrix *)_matrix
   shouldPlaceObject:(id)_object
-  atPosition:(unsigned)_x:(unsigned)_y
+  atPosition:(unsigned)_x :(unsigned)_y
 {
   id   _row, _col;
   BOOL doPlace;
