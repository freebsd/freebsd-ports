--- src/WP_Terrain.C.orig	Tue Nov 19 01:14:04 2002
+++ src/WP_Terrain.C	Tue Nov 19 01:14:18 2002
@@ -23,6 +23,8 @@
 #include "WP_Quad.h"
 #include "WP_Terrain.h"
 
+using namespace std;
+
 WP_Terrain::WP_Terrain(int _width, int _height, int number_iterations, scalar resolution, int scale): 
   width(_width), height(_height), displayID(0), height_map(0)
 {
