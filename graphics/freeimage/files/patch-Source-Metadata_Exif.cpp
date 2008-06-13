--- Source/Metadata/Exif.cpp.orig	2008-06-13 16:09:38.000000000 +0200
+++ Source/Metadata/Exif.cpp	2008-06-13 16:10:15.000000000 +0200
@@ -495,7 +495,7 @@
 		}
 
 		// remember that we've visited this directory so that we don't visit it again later
-		DWORD visited = (((DWORD)ifdp & 0xFFFF) << 16) | (DWORD)de;
+		DWORD visited = (((size_t)ifdp & (size_t)0xFFFF) << 16) | (DWORD)de;
 		if(visitedIFD.find(visited) != visitedIFD.end()) {
 			continue;
 		} else {
