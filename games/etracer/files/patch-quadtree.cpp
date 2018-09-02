quadtree.cpp:860:29: error: ordered comparison between pointer and zero
      ('TTexture *' and 'int')
                                if (TerrList[j].texture > 0) {
                                    ~~~~~~~~~~~~~~~~~~~ ^ ~

--- quadtree.cpp.orig	2018-08-19 09:03:02 UTC
+++ quadtree.cpp
@@ -857,7 +857,7 @@ void quadsquare::Render (const quadcornerdata& cd, GLu
 			}
 
 			for (size_t j=0; j<numTerrains; j++) {
-				if (TerrList[j].texture > 0) {
+				if (TerrList[j].texture != 0) {
 					Course.TerrList[j].texture->Bind();
 
 					for (GLuint i=0; i<VertexArrayCounter; i++) {
