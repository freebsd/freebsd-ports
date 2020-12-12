--- source/providers/file_provider.cpp.orig	2020-12-06 20:40:57 UTC
+++ source/providers/file_provider.cpp
@@ -10,7 +10,7 @@
 #include "helpers/project_file_handler.hpp"
 
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
     #define off64_t off_t
     #define fopen64 fopen
     #define fseeko64 fseek
