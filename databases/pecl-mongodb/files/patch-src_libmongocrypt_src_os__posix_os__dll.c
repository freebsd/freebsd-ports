--- src/libmongocrypt/src/os_posix/os_dll.c.orig	2024-03-10 13:26:23.114373000 +0100
+++ src/libmongocrypt/src/os_posix/os_dll.c	2024-03-10 13:26:34.648726000 +0100
@@ -98,6 +98,7 @@
 #elif defined(__linux__) || defined(__FreeBSD__)
 
 #include <link.h>
+#include <dlfcn.h>
 
 mcr_dll_path_result mcr_dll_path(mcr_dll dll) {
     struct link_map *map;
