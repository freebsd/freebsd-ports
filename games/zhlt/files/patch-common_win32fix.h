--- common/win32fix.h.orig	2016-03-30 06:24:01 UTC
+++ common/win32fix.h
@@ -5,7 +5,7 @@
 #pragma once
 #endif
 
-#include <malloc.h>
+#include <stdlib.h>
 
 /////////////////////////////
 #ifdef SYSTEM_WIN32
@@ -50,6 +50,19 @@
 
 #define INLINE inline
 
+#define _close close
+#define _open open
+#define _read read
+#define _strdup strdup
+#define _strlwr strlwr
+#define _strupr strupr
+#define _unlink unlink
+
+#define fscanf_s fscanf
+#define sprintf_s(str, ...) snprintf(str, sizeof(str), __VA_ARGS__)
+#define sscanf_s sscanf
+#define strcpy_s(dst, src) strlcpy(dst, src, sizeof(dst))
+
 #endif
 /////////////////////////////
 
