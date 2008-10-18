$FreeBSD$

--- ../../hotspot/src/os/bsd/vm/os_bsd.cpp.orig	Wed Jun 13 16:16:36 2007
+++ ../../hotspot/src/os/bsd/vm/os_bsd.cpp	Wed Jun 13 16:36:13 2007
@@ -364,7 +364,7 @@
  *	  7: The default directories, normally /lib and /usr/lib.
  */
 #ifndef DEFAULT_LIBPATH
-#define DEFAULT_LIBPATH	"/lib:/usr/lib"
+#define DEFAULT_LIBPATH	"/lib:/usr/lib:%%LOCALBASE%%/lib"
 #endif
 
 #define EXTENSIONS_DIR	"/lib/ext"
@@ -1431,10 +1431,10 @@
 void os::Bsd::clock_init() {
   struct timespec res;
   struct timespec tp;
-  if (clock_getres(CLOCK_MONOTONIC, &res) == 0 &&
-      clock_gettime(CLOCK_MONOTONIC, &tp)  == 0) {
+  if (::clock_getres(CLOCK_MONOTONIC, &res) == 0 &&
+      ::clock_gettime(CLOCK_MONOTONIC, &tp)  == 0) {
     // yes, monotonic clock is supported
-    _clock_gettime = clock_gettime;
+    _clock_gettime = ::clock_gettime;
   }
 }
 #else
