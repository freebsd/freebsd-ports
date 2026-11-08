--- waftools/parallel.py.orig	2026-09-11 16:05:37 UTC
+++ waftools/parallel.py
@@ -321,6 +321,13 @@ long read_vmsize()
 
 long read_vmsize()
 {
+#if defined(__FreeBSD__)
+/*
+	Just deactivated. If really needed see
+	https://forums.freebsd.org/threads/how-to-get-virtual-memory-size-of-current-process-in-c-c.87022/post-587358
+*/
+    return 0;
+#else
     static char filename[80];
     static char sbuf[1024];
     char* str;
@@ -336,6 +343,7 @@ long read_vmsize()
 
     str = strstr(sbuf, "VmSize:") + 8;
     return atol(str);
+#endif
 }
 
 long read_memory_currrent() {
