quadtree.cpp:860:29: error: ordered comparison between pointer and zero
      ('TTexture *' and 'int')
                                if (TerrList[j].texture > 0) {
                                    ~~~~~~~~~~~~~~~~~~~ ^ ~

--- src/quadtree.cpp.orig	2018-09-01 16:45:10 UTC
+++ src/quadtree.cpp
@@ -782,7 +782,7 @@ void quadsquare::Render(const quadcornerdata& cd, GLub
 			}
 
 			for (size_t j=0; j<numTerrains; j++) {
-				if (Course.TerrList[j].texture > 0) {
+				if (Course.TerrList[j].texture != NULL) {
 					Course.TerrList[j].texture->Bind();
 
 					for (GLuint i=0; i<VertexArrayCounter; i++) {
