--- drivers/gles2/rasterizer_gles2.cpp.orig	2018-01-10 11:36:45 UTC
+++ drivers/gles2/rasterizer_gles2.cpp
@@ -2135,9 +2135,9 @@ Error RasterizerGLES2::_surface_set_arra
 					for (int i = 0; i < p_surface->array_len; i++) {
 
 						GLbyte vector[4] = {
-							CLAMP(src[i].x * 127, -128, 127),
-							CLAMP(src[i].y * 127, -128, 127),
-							CLAMP(src[i].z * 127, -128, 127),
+							static_cast<GLbyte>CLAMP(src[i].x * 127, -128, 127),
+							static_cast<GLbyte>CLAMP(src[i].y * 127, -128, 127),
+							static_cast<GLbyte>CLAMP(src[i].z * 127, -128, 127),
 							0,
 						};
 
@@ -2169,10 +2169,10 @@ Error RasterizerGLES2::_surface_set_arra
 					for (int i = 0; i < p_surface->array_len; i++) {
 
 						GLbyte xyzw[4] = {
-							CLAMP(src[i * 4 + 0] * 127, -128, 127),
-							CLAMP(src[i * 4 + 1] * 127, -128, 127),
-							CLAMP(src[i * 4 + 2] * 127, -128, 127),
-							CLAMP(src[i * 4 + 3] * 127, -128, 127)
+							static_cast<GLbyte>CLAMP(src[i * 4 + 0] * 127, -128, 127),
+							static_cast<GLbyte>CLAMP(src[i * 4 + 1] * 127, -128, 127),
+							static_cast<GLbyte>CLAMP(src[i * 4 + 2] * 127, -128, 127),
+							static_cast<GLbyte>CLAMP(src[i * 4 + 3] * 127, -128, 127)
 						};
 
 						copymem(&p_mem[a.ofs + i * stride], xyzw, a.size);
