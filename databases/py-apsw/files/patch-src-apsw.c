--- src/apsw.c.orig	2023-09-13 22:45:44 UTC
+++ src/apsw.c
@@ -102,7 +102,7 @@ API Reference
 #ifdef _MSC_VER
 #include <malloc.h>
 #else
-#include <alloca.h>
+#include <stdlib.h>
 #endif
 
 /* Get the version number */
