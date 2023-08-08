--- src/libmongocrypt/src/os_posix/os_dll.c.orig	2023-02-09 10:59:51 UTC
+++ src/libmongocrypt/src/os_posix/os_dll.c
@@ -17,6 +17,7 @@
 
 #include "../mongocrypt-dll-private.h"
 
+#define _WIN32
 #ifndef _WIN32
 
 #include <assert.h>
