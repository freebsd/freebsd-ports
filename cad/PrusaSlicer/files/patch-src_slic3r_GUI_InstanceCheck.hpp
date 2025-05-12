--- src/slic3r/GUI/InstanceCheck.hpp.orig	2025-04-10 11:26:51 UTC
+++ src/slic3r/GUI/InstanceCheck.hpp
@@ -16,7 +16,7 @@
 
 #include <boost/filesystem.hpp>
 
-#if __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <boost/thread.hpp>
 #include <mutex>
 #include <condition_variable>
@@ -44,7 +44,7 @@ class MainFrame;
 
 class MainFrame;
 
-#if __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     #define BACKGROUND_MESSAGE_LISTENER
 #endif // __linux__
 
