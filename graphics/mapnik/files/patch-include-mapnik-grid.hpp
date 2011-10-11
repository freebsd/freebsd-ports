--- include/mapnik/grid/grid.hpp.orig	2011-10-09 13:38:31.962692544 +0400
+++ include/mapnik/grid/grid.hpp	2011-10-09 13:38:53.371691622 +0400
@@ -284,7 +284,7 @@
         {
 
 #ifdef MAPNIK_BIG_ENDIAN
-            unsigned a1 = (int)((rgba1 & 0xff) * opacity) & 0xff; // adjust for desired opacity
+            unsigned a = (int)((rgba1 & 0xff) * opacity) & 0xff; // adjust for desired opacity
 #else
             unsigned a = (int)(((rgba1 >> 24) & 0xff) * opacity) & 0xff; // adjust for desired opacity
 #endif                    
