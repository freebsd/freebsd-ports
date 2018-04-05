--- src/Lib/terragear/tg_shapefile.cxx.orig	2017-10-07 06:58:20 UTC
+++ src/Lib/terragear/tg_shapefile.cxx
@@ -152,7 +152,7 @@
     }
 
     // close after each write
-    if ( ds_id >= 0 ) {
+    if ( ds_id >= (void *)0 ) {
         ds_id = tgShapefile::CloseDatasource( ds_id );
     }
 }
