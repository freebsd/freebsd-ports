--- src/kex/psnprntf.c.orig	2026-02-14 18:11:41 UTC
+++ src/kex/psnprntf.c
@@ -14,6 +14,7 @@
 #ifndef _DEFAULT_SOURCE
 #define _DEFAULT_SOURCE
 #endif
+#endif
 
 #include <string.h> /* for memset */
 #include <stdarg.h> /* for va_list */
@@ -23,6 +24,7 @@
 
 #include "psnprntf.h"
 
+#if defined(__linux__) && !defined(_WIN32)
 #ifndef _SVID_SOURCE
 #define _SVID_SOURCE
 #endif
@@ -31,6 +33,27 @@
 /* FCVT macro: MSVC uses _fcvt, others use fcvt */
 #if defined(_MSC_VER)
 #define FCVT _fcvt
+#elif defined(__FreeBSD__)
+/* FreeBSD never had fcvt(); emulate it with snprintf. */
+#include <stdio.h>
+static char *d64_fcvt(double value, int ndigit, int *decpt, int *sign) {
+    static char buf[512];
+    char *dot;
+
+    *sign = value < 0.0;
+    snprintf(buf, sizeof(buf), "%.*f", ndigit < 0 ? 0 : ndigit,
+             *sign ? -value : value);
+    dot = strchr(buf, '.');
+    if(dot) {
+        *decpt = (int)(dot - buf);
+        memmove(dot, dot + 1, strlen(dot));
+    }
+    else {
+        *decpt = (int)strlen(buf);
+    }
+    return buf;
+}
+#define FCVT d64_fcvt
 #else
 #define FCVT fcvt
 #endif
