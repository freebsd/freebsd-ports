--- src/bvar/default_variables.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/bvar/default_variables.cpp
@@ -449,6 +449,9 @@ static bool read_proc_io(ProcIO* s) {
         return false;
     }
     return true;
+#elif defined(OS_FREEBSD)
+    memset(s, 0, sizeof(ProcIO));
+    return false;
 #elif defined(OS_MACOSX)
     // TODO(zhujiashun): get rchar, wchar, syscr, syscw, cancelled_write_bytes
     // in MacOS.
