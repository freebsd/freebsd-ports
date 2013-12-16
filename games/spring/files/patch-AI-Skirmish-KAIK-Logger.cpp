--- AI/Skirmish/KAIK/Logger.cpp.orig	2013-03-26 03:58:45.000000000 +0400
+++ AI/Skirmish/KAIK/Logger.cpp	2013-11-11 03:18:04.431773779 +0400
@@ -14,8 +14,7 @@
 
 	time_t now1;
 	time(&now1);
-//FIXME:compile hack for macosx
-#undef tm
+
 	struct tm* now2 = localtime(&now1);
 
 	std::stringstream ss;
