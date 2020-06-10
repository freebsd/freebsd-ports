--- src/LV2/xputty/header/xasprintf.h.orig	2020-06-10 01:09:00 UTC
+++ src/LV2/xputty/header/xasprintf.h
@@ -11,6 +11,8 @@
 #ifndef XASPRINTF_H_
 #define XASPRINTF_H_
 
+#include <cstdarg>
+
 #ifdef __cplusplus
 extern "C" {
 #endif
