--- src/surface_cache.cpp.orig	2018-06-16 13:59:29.319430000 +0300
+++ src/surface_cache.cpp	2018-06-16 14:00:09.140102000 +0300
@@ -116,7 +116,7 @@
 	}
 #endif // ANDROID
 	//std::cerr << "loading image '" << fname << "'\n";
-	if(surf.get() == false || surf->w == 0) {
+	if(surf.get() == nullptr || surf->w == 0) {
 		if(key != "") {
 			std::cerr << "failed to load image '" << key << "'\n";
 		}
