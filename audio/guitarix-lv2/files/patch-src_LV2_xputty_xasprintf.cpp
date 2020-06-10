--- src/LV2/xputty/xasprintf.cpp.orig	2020-06-10 01:06:22 UTC
+++ src/LV2/xputty/xasprintf.cpp
@@ -25,7 +25,7 @@ int _vscprintf_so(const char * format, va_list pargs) 
 int vasprintf(char **strp, const char *fmt, va_list ap) {
     int len = _vscprintf_so(fmt, ap);
     if (len == -1) return -1;
-    char *str = malloc((size_t) len + 1);
+    char *str = (char*)malloc((size_t) len + 1);
     if (!str) return -1;
     int r = vsnprintf(str, len + 1, fmt, ap);
     if (r == -1) return free(str), -1;
