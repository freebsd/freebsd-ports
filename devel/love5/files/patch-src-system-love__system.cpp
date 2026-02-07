--- src/system/love_system.cpp.orig	2008-09-20 18:40:14.000000000 +0400
+++ src/system/love_system.cpp	2011-09-27 07:49:03.000000000 +0400
@@ -83,7 +83,7 @@
 #ifdef WIN32
 		bool embedded = (leaf.compare("love.exe") != 0);
 #else
-		bool embedded = (leaf.compare("love") != 0);
+		bool embedded = (leaf.compare("love5") != 0);
 #endif
 
 		std::string base;
