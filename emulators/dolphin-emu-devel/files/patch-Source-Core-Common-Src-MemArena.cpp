--- Source/Core/Common/Src/MemArena.cpp.orig	2012-09-13 15:55:31.000000000 +0200
+++ Source/Core/Common/Src/MemArena.cpp	2012-09-13 15:55:51.000000000 +0200
@@ -29,7 +29,7 @@
 #include <cstring>
 #endif
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined (__FreeBSD__)
 static const char* ram_temp_file = "/tmp/gc_mem.tmp";
 #elif !defined(_WIN32) // non OSX unixes
 static const char* ram_temp_file = "/dev/shm/gc_mem.tmp";
