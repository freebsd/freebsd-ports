--- src/rtapi/rtapi_uspace.hh.orig	2016-06-25 02:19:12 UTC
+++ src/rtapi/rtapi_uspace.hh
@@ -17,14 +17,21 @@
  */
 #ifndef RTAPI_USPACE_HH
 #define RTAPI_USPACE_HH
+#ifdef __linux__
 #include <sys/fsuid.h>
+#endif
 #include <unistd.h>
 #include <pthread.h>
 
 struct WithRoot
 {
+#ifdef __linux__
     WithRoot() { if(!level) setfsuid(geteuid()); level++; }
     ~WithRoot() { --level; if(!level) setfsuid(getuid()); }
+#else
+    WithRoot() { if(!level) level++; }
+    ~WithRoot() { --level; if(!level) seteuid(getuid()); }
+#endif
     static int level;
 };
 
