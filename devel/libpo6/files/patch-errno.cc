--- errno.cc.orig	2018-08-17 03:05:05 UTC
+++ errno.cc
@@ -27,7 +27,6 @@
 
 // C
 #include <string.h>
-#include <string.h>
 
 // POSIX
 #include <errno.h>
@@ -43,12 +42,17 @@ po6 :: strerror(int err)
     memset(buf, 0, sizeof(buf));
 
     errno = 0;
-#if (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && ! _GNU_SOURCE
+#if _GNU_SOURCE
+    // GNU
+    char* ret = strerror_r(err, buf, sizeof(buf));
+
+    if (ret != buf)
+    {
+        strncpy(buf, ret, sizeof(buf));
+    }
+#else
     // XSI-compliant
     errno = strerror_r(err, buf, sizeof(buf));
-#else
-    // GNU
-    strncpy(buf, strerror_r(err, buf, sizeof(buf)), sizeof(buf));
 #endif
     int obs = errno;
     errno = saved;
@@ -62,9 +66,7 @@ po6 :: strerror(int err)
     return std::string(buf);
 }
 
-#define XSTR(x) #x
-#define STR(x) XSTR(x)
-#define CSTRINGIFY(x) if ((x) == err) { return STR(x); }
+#define CSTRINGIFY(x) if ((x) == err) { return #x; }
 
 const char*
 po6 :: strerrno(int err)
