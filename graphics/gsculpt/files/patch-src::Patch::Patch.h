--- ./src/Patch/Patch.h.orig	Mon Jul 21 16:20:46 2003
+++ ./src/Patch/Patch.h	Mon Jul 21 16:27:54 2003
@@ -7,6 +7,8 @@
 
 #include <vector>
 
+using std::vector;
+
 //generates the indices of the vertices which make up quadrilateral faces, which
 //form a rectangular patch
 void patchGenerateQuadList(vector<int>& quads, int widthFaces, int heightFaces,
