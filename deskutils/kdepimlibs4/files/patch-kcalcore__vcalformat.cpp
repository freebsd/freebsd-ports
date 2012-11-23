--- kcalcore/vcalformat.cpp.orig	2012-11-23 17:03:35.000000000 +0800
+++ kcalcore/vcalformat.cpp	2012-11-23 17:04:14.000000000 +0800
@@ -1190,8 +1190,7 @@
   if ( ( vo = isAPropertyOf( vtodo, VCRRuleProp ) ) != 0 ) {
     QString tmpStr = ( s = fakeCString( vObjectUStringZValue( vo ) ) );
     deleteStr( s );
-    tmpStr.simplified();
-    tmpStr = tmpStr.toUpper();
+    tmpStr = tmpStr.simplified().toUpper();
     // first, read the type of the recurrence
     int typelen = 1;
     uint type = Recurrence::rNone;
@@ -1674,8 +1673,7 @@
   if ( ( vo = isAPropertyOf( vevent, VCRRuleProp ) ) != 0 ) {
     QString tmpStr = ( s = fakeCString( vObjectUStringZValue( vo ) ) );
     deleteStr( s );
-    tmpStr.simplified();
-    tmpStr = tmpStr.toUpper();
+    tmpStr = tmpStr.simplified().toUpper();
     // first, read the type of the recurrence
     int typelen = 1;
     uint type = Recurrence::rNone;
