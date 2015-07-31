--- Core/FileLoaders/HTTPFileLoader.cpp.orig	2015-07-11 22:44:11 UTC
+++ Core/FileLoaders/HTTPFileLoader.cpp
@@ -15,6 +15,9 @@
 // Official git repository and contact information can be found at
 // https://github.com/hrydgard/ppsspp and http://www.ppsspp.org/.
 
+// XXX ports/193528
+#define _GLIBCXX_USE_C99 1
+
 #include <algorithm>
 #include "base/stringutil.h"
 #include "Common/Common.h"
@@ -53,11 +56,7 @@ HTTPFileLoader::HTTPFileLoader(const std
 			}
 			if (size_pos != header.npos) {
 				// TODO: Find a way to get this to work right on Symbian?
-#ifndef __SYMBIAN32__
-				filesize_ = atoll(&header[size_pos]);
-#else
-				filesize_ = atoi(&header[size_pos]);
-#endif
+				filesize_ = std::atoll(&header[size_pos]);
 			}
 		}
 		if (startsWithNoCase(header, "Accept-Ranges:")) {
