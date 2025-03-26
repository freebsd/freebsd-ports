--- src/LV2/xputty/header/xasprintf.h.orig	2022-05-02 18:38:03 UTC
+++ src/LV2/xputty/header/xasprintf.h
@@ -15,6 +15,8 @@
 #include <stdlib.h>
 #include <stdarg.h>
 
+#include <cstdarg>
+
 #ifdef __cplusplus
 extern "C" {
 #endif
