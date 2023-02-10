--- third_party/swiftshader/third_party/marl/src/memory.cpp.orig	2022-02-07 13:39:41 UTC
+++ third_party/swiftshader/third_party/marl/src/memory.cpp
@@ -19,7 +19,7 @@
 
 #include <cstring>
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__OpenBSD__)
 #include <sys/mman.h>
 #include <unistd.h>
 namespace {
