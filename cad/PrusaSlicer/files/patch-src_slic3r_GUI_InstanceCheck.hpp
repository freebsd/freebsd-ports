--- src/slic3r/GUI/InstanceCheck.hpp.orig	2023-07-25 11:12:36 UTC
+++ src/slic3r/GUI/InstanceCheck.hpp
@@ -11,7 +11,7 @@
 
 #include <boost/filesystem.hpp>
 
-#if __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <boost/thread.hpp>
 #include <mutex>
 #include <condition_variable>
@@ -38,7 +38,7 @@ class MainFrame;
 
 class MainFrame;
 
-#if __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     #define BACKGROUND_MESSAGE_LISTENER
 #endif // __linux__
 
