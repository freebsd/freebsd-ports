--- src/real_dlsym.cpp.orig	2023-04-13 17:40:23 UTC
+++ src/real_dlsym.cpp
@@ -23,6 +23,8 @@ static void get_real_functions()
     const char* libs[] = {
 #if defined(__GLIBC__)
         "*libdl.so*",
+#elif defined(__FreeBSD__)
+        "*ld-elf.so*",
 #endif
         "*libc.so*",
         "*libc.*.so*",
