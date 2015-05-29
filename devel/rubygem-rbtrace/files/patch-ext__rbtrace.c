--- ext/rbtrace.c.orig	2015-05-29 10:59:59 UTC
+++ ext/rbtrace.c
@@ -40,6 +40,16 @@
 #define RSTRING_LEN(str) RSTRING(str)->len
 #endif
 
+
+#ifdef __FreeBSD__
+ #define PLATFORM_FREEBSD
+#endif
+
+#ifdef __linux__
+ #define PLATFORM_LINUX
+#endif
+
+
 static uint64_t
 ru_utime_usec()
 {
@@ -953,7 +963,14 @@ rbtrace__process_event(msgpack_object cm
 
     if (outer == 0) {
       rb_eval_string_protect("$0 = \"[DEBUG] #{Process.ppid}\"", 0);
+
+#ifdef PLATFORM_FREEBSD
+      // The call setpgrp() is equivalent to setpgid(0,0).
+      setpgid(0,0);
+#else
       setpgrp();
+#endif
+
       pid_t inner = fork();
 
       if (inner == 0) {
