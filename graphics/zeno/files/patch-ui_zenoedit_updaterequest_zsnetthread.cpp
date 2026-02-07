--- ui/zenoedit/updaterequest/zsnetthread.cpp.orig	2023-11-22 19:17:26 UTC
+++ ui/zenoedit/updaterequest/zsnetthread.cpp
@@ -37,7 +37,7 @@ void ZsNetThread::run()
 
 void ZsNetThread::netGet()
 {
-#ifdef __linux__
+#if defined( __linux__) || defined(__FreeBSD__)
     return;
 #else
     CURL* curl;
