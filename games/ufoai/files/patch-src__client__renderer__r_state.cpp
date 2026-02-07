--- ./src/client/renderer/r_state.cpp.orig	2014-06-05 06:18:39.000000000 +0200
+++ ./src/client/renderer/r_state.cpp	2014-08-07 16:49:53.695310143 +0200
@@ -147,7 +147,8 @@
 
 void R_BindArray (GLenum target, GLenum type, const void* array)
 {
-	switch (target) {
+	const int v = static_cast<int>(target);
+	switch (v) {
 	case GL_VERTEX_ARRAY:
 		glVertexPointer(COMPONENTS_VERTEX_ARRAY3D, type, 0, array);
 		break;
@@ -180,7 +181,8 @@
  */
 void R_BindDefaultArray (GLenum target)
 {
-	switch (target) {
+	const int v = static_cast<int>(target);
+	switch (v) {
 	case GL_VERTEX_ARRAY:
 		R_BindArray(target, GL_FLOAT, r_state.vertex_array_3d);
 		break;
