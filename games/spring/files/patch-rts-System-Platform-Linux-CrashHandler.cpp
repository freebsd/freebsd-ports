--- rts/System/Platform/Linux/CrashHandler.cpp.orig	2013-03-26 03:58:36.000000000 +0400
+++ rts/System/Platform/Linux/CrashHandler.cpp	2013-11-09 00:15:32.446878961 +0400
@@ -323,7 +323,7 @@
 
 static void ForcedExitAfterTenSecs() {
 	boost::this_thread::sleep(boost::posix_time::seconds(10));
-	std::_Exit(-1);
+	exit(-1);
 }
 
 
