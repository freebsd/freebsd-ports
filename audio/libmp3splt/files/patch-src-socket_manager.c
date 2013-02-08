--- src/socket_manager.c.orig	2013-01-31 20:18:07.000000000 +0400
+++ src/socket_manager.c	2013-01-31 20:20:31.000000000 +0400
@@ -48,8 +48,6 @@
 
 #ifdef __WIN32__
 #include <malloc.h>
-#else
-#include <alloca.h>
 #endif
 
 #include <string.h>
