--- WP_Terrain.C.orig	Thu Aug 19 15:07:13 2004
+++ WP_Terrain.C	Thu Aug 19 15:07:26 2004
@@ -29,7 +29,7 @@
 {
   //creates a random 3D terrain
 
-  WP_Vertex **height_map = new (WP_Vertex*)[height];
+  WP_Vertex **height_map = new WP_Vertex*[height];
   if (!height_map)
     {
       cerr << "Unable to allocate memory for height_map" << endl;
