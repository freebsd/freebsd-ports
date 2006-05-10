--- client/timecvt.cpp.orig	Fri Jul  2 23:21:09 2004
+++ client/timecvt.cpp	Wed May 10 11:15:17 2006
@@ -40,6 +40,15 @@
 #include "s_util.h"
 #include "timecvt.h"
 
+/* safe_strncpy() from boinc-client-5.2.15 lib/util.C
+ * The function got removed from boinc-client-5.4.X */
+// "safe" means the output will be null-terminated.
+//
+void safe_strncpy(char* dst, const char* src, int len) {
+    strncpy(dst, src, len);
+    dst[len-1]=0;
+}
+
 void timecvt_start() {}
 
 static void trim_newline(char*p) {
