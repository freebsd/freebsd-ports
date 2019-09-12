--- adb/client/adb_install.cpp.orig	2019-08-13 02:10:58 UTC
+++ adb/client/adb_install.cpp
@@ -214,7 +214,7 @@ static int install_app_streamed(int argc, const char**
             return 1;
         }
 
-#ifdef __linux__
+#if !defined(__APPLE__) && !defined(_WIN32)
         posix_fadvise(local_fd.get(), 0, 0, POSIX_FADV_SEQUENTIAL | POSIX_FADV_NOREUSE);
 #endif
 
