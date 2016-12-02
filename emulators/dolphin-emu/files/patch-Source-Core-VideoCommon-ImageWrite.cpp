Add missing header for errno

--- Source/Core/VideoCommon/ImageWrite.cpp.orig	2016-12-01 14:49:37.182934391 +0000
+++ Source/Core/VideoCommon/ImageWrite.cpp	2016-12-01 14:51:32.373069616 +0000
@@ -2,6 +2,7 @@
 // Licensed under GPLv2+
 // Refer to the license.txt file included.
 
+#include <cerrno>
 #include <list>
 #include <string>
 
