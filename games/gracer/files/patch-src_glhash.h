--- src/glhash.h.orig	2000-03-01 04:09:04 UTC
+++ src/glhash.h
@@ -709,6 +709,8 @@ glWordList glwordlist[] = {
 	{"all_attrib_bits",	GL_ALL_ATTRIB_BITS},
 	{"client_pixel_store_bit",	GL_CLIENT_PIXEL_STORE_BIT},
 	{"client_vertex_array_bit",	GL_CLIENT_VERTEX_ARRAY_BIT},
+#ifdef GL_CLIENT_ALL_ATTRIB_BITS
 	{"client_all_attrib_bits",	GL_CLIENT_ALL_ATTRIB_BITS},
+#endif
 	{NULL, GL_NONE},
 };
