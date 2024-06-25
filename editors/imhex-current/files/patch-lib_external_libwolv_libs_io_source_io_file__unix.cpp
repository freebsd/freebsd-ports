--- lib/external/libwolv/libs/io/source/io/file_unix.cpp.orig	2024-06-15 11:20:54 UTC
+++ lib/external/libwolv/libs/io/source/io/file_unix.cpp
@@ -5,7 +5,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 
-#if defined(OS_MACOS)
+#if defined(OS_MACOS) || defined(OS_FREEBSD)
     #include <sys/types.h>
     #include <sys/event.h>
 #elif defined(OS_LINUX)
@@ -85,7 +85,11 @@ namespace wolv::io {
         if (!isValid())
             return false;
 
+    #if defined(OS_FREEBSD)
+        m_map = static_cast<u8*>(mmap(nullptr, m_fileSize, PROT_READ | PROT_WRITE, MAP_SHARED, m_handle, 0));
+    #else
         m_map = static_cast<u8*>(mmap(nullptr, m_fileSize, m_mode == Mode::Read ? PROT_READ : PROT_READ | PROT_WRITE, MAP_SHARED, m_handle, 0));
+    #endif
 
         return true;
     }
@@ -182,7 +186,7 @@ namespace wolv::io {
     }
 
 
-    #if defined(OS_MACOS)
+    #if defined(OS_MACOS) || defined(OS_FREEBSD)
         void ChangeTracker::trackImpl(const bool &stopped, const std::fs::path &path, const std::function<void()> &callback) {
             int queue = kqueue();
             if (queue == -1)
