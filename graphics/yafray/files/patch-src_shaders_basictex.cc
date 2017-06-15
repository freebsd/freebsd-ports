--- src/shaders/basictex.cc.orig	2006-06-10 00:41:26 UTC
+++ src/shaders/basictex.cc
@@ -259,7 +259,7 @@ textureImage_t::textureImage_t(const cha
 		intp_type = BICUBIC;
 	
 	// Load image, try to determine from extensions first
-	char *ext = strrchr(filename, '.');
+	const char *ext = strrchr(filename, '.');
 	bool jpg_tried = false;
 	bool tga_tried = false;
 	bool hdr_tried = false;
