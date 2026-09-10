--- libs/ctx/libgegl_ctx/ctx.h.orig	2026-09-07 02:51:56 UTC
+++ libs/ctx/libgegl_ctx/ctx.h
@@ -51,7 +51,7 @@ extern "C" {
 #include <string.h>
 #ifndef _WIN32
 #include <strings.h>
-#include <alloca.h>
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
