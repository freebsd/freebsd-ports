$FreeBSD$

--- ../../hotspot/src/os/bsd/vm/os_bsd.cpp.orig	Tue Jan 27 17:54:28 2004
+++ ../../hotspot/src/os/bsd/vm/os_bsd.cpp	Tue Jan 27 17:55:21 2004
@@ -333,7 +333,7 @@
 #define malloc(n) (char*)NEW_C_HEAP_ARRAY(char, (n))
 #define getenv(n) ::getenv(n)
 
-#define DEFAULT_LD_LIBRARY_PATH "/usr/lib" /* See ld.so.1(1) */
+#define DEFAULT_LD_LIBRARY_PATH "/usr/lib:%%LOCALBASE%%/lib" /* See ld.so.1(1) */
 #define EXTENSIONS_DIR "/lib/ext"
 #define ENDORSED_DIR "/lib/endorsed"
 
@@ -1968,16 +1968,23 @@
 
 static int os_sleep(jlong millis, bool interruptible) {
   int res;
-  if (!interruptible) {
-    do {
-	res = os_nanosleep(&millis);
-    } while ((res == OS_ERR) && (errno == EINTR) && (millis > 0));
-  } else {
-    INTERRUPTIBLE_NORESTART_VM(os_nanosleep(&millis), res, os::Bsd::clear_interrupted);
+
+  while (millis > 0) {
+    if (!interruptible) {
+      res = os_nanosleep(&millis);
+    } else {
+      INTERRUPTIBLE_NORESTART_VM(os_nanosleep(&millis), res, os::Bsd::clear_interrupted);
+    }
+    // INTERRUPTIBLE_NORESTART_VM returns res == OS_INTRPT for thread.Interrupt
+
+    if((res == OS_ERR) && (errno == EINTR)) {
+      if(millis <= 0)
+	return OS_OK;
+    } else
+      return res;
   }
-  // INTERRUPTIBLE_NORESTART_VM returns res == OS_INTRPT for thread.Interrupt
 
-  return res;
+  return OS_OK;
 }
 
 int os::Bsd::naked_sleep() {
