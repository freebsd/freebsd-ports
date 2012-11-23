--- kcal/vcalformat.cpp.orig	2012-11-23 17:05:03.000000000 +0800
+++ kcal/vcalformat.cpp	2012-11-23 17:05:32.000000000 +0800
@@ -1029,8 +1029,7 @@
   if ( ( vo = isAPropertyOf( vevent, VCRRuleProp ) ) != 0 ) {
     QString tmpStr = ( s = fakeCString( vObjectUStringZValue( vo ) ) );
     deleteStr( s );
-    tmpStr.simplified();
-    tmpStr = tmpStr.toUpper();
+    tmpStr = tmpStr.simplified().toUpper();
 
     // first, read the type of the recurrence
     int typelen = 1;
