--- src/DETHRACE/pc-all/allnet.c.orig	2026-06-28 21:41:50 UTC
+++ src/DETHRACE/pc-all/allnet.c
@@ -15,6 +15,7 @@
 #include <ctype.h>
 #include <stdlib.h>
 #include <string.h>
+#include <netinet/in.h>
 
 #ifdef _WIN32
 #define _WINSOCK_DEPRECATED_NO_WARNINGS
