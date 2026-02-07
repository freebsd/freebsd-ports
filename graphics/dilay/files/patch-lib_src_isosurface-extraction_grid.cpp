--- lib/src/isosurface-extraction/grid.cpp.orig	2020-10-19 21:28:22 UTC
+++ lib/src/isosurface-extraction/grid.cpp
@@ -50,7 +50,7 @@ namespace
     false, true,  false, true,  false, false, false, false, false, false, false, false, true,
     false, false, true,  false, false, false, false, false, false};
 
-  static char vertexIndicesByConfiguration[256][12] = {
+  static signed char vertexIndicesByConfiguration[256][12] = {
     {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
     {0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1},
     {0, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1},
@@ -313,7 +313,7 @@ namespace
 
   unsigned char numVertices (unsigned char configuration)
   {
-    char n = -1;
+    signed char n = -1;
     for (unsigned char i = 0; i < 12; i++)
     {
       n = std::max (n, vertexIndicesByConfiguration[configuration][i]);
@@ -375,10 +375,10 @@ namespace
         const unsigned char edge3 = edgeIndicesByFace[i][2];
         const unsigned char edge4 = edgeIndicesByFace[i][3];
 
-        const char vertex1 = vertexIndicesByConfiguration[this->configuration][edge1];
-        const char vertex2 = vertexIndicesByConfiguration[this->configuration][edge2];
-        const char vertex3 = vertexIndicesByConfiguration[this->configuration][edge3];
-        const char vertex4 = vertexIndicesByConfiguration[this->configuration][edge4];
+        const signed char vertex1 = vertexIndicesByConfiguration[this->configuration][edge1];
+        const signed char vertex2 = vertexIndicesByConfiguration[this->configuration][edge2];
+        const signed char vertex3 = vertexIndicesByConfiguration[this->configuration][edge3];
+        const signed char vertex4 = vertexIndicesByConfiguration[this->configuration][edge4];
 
         if (vertex1 != -1 && vertex2 != -1 && vertex3 != -1 && vertex4 != -1)
         {
@@ -633,7 +633,7 @@ struct IsosurfaceExtractionGrid::Impl
   }
 
   bool hasAmbiguousNeighbor (const Cube& cube, unsigned int x, unsigned int y, unsigned int z,
-                             unsigned char ambiguousFace, char dim)
+                             unsigned char ambiguousFace, signed char dim)
   {
     assert (cube.nonManifoldConfig ());
     assert (dim == -3 || dim == -2 || dim == -1 || dim == 1 || dim == 2 || dim == 3);
