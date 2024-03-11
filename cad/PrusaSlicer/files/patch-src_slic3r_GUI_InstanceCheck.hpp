--- src/slic3r/GUI/InstanceCheck.hpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/InstanceCheck.hpp
@@ -15,7 +15,7 @@
 
 #include <boost/filesystem.hpp>
 
-#if __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <boost/thread.hpp>
 #include <mutex>
 #include <condition_variable>
@@ -42,7 +42,7 @@ namespace GUI {
 
 class MainFrame;
 
-#if __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     #define BACKGROUND_MESSAGE_LISTENER
 #endif // __linux__
 
