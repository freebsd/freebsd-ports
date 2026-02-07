--- aces_formatter.cpp.orig	2018-06-23 19:34:29 UTC
+++ aces_formatter.cpp
@@ -107,8 +107,8 @@
 #include <cassert>
 
 struct scanLineHeader {
-	int32	yCoordinate;
-	int32	pixelDataSize;
+	uint32	yCoordinate;
+	uint32	pixelDataSize;
 };
 
 
