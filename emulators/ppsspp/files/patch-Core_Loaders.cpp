--- Core/Loaders.cpp.orig	2015-02-26 20:05:06 UTC
+++ Core/Loaders.cpp
@@ -15,6 +15,9 @@
 // Official git repository and contact information can be found at
 // https://github.com/hrydgard/ppsspp and http://www.ppsspp.org/.
 
+// XXX ports/193528
+#define _GLIBCXX_USE_C99 1
+
 #include <algorithm>
 #include <cstdio>
 
@@ -310,12 +313,7 @@ HTTPFileLoader::HTTPFileLoader(const std
 				size_pos = header.find_first_not_of(' ', size_pos);
 			}
 			if (size_pos != header.npos) {
-				// TODO: Find a way to get this to work right on Symbian?
-#ifndef __SYMBIAN32__
-				filesize_ = atoll(&header[size_pos]);
-#else
-				filesize_ = atoi(&header[size_pos]);
-#endif
+				filesize_ = std::atoll(&header[size_pos]);
 			}
 		}
 		if (startsWithNoCase(header, "Accept-Ranges:")) {
