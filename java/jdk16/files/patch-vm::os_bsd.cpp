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
 
@@ -1898,7 +1898,7 @@
     } while ((res == OS_ERR) && (errno == EINTR));
   } else {
     assert(Thread::current()->is_Java_thread(), "must be java thread");
-    INTERRUPTIBLE_NORESTART(nanosleep(&t, &t), res, os::Bsd::clear_interrupted);
+    INTERRUPTIBLE_NORESTART_VM(nanosleep(&t, &t), res, os::Bsd::clear_interrupted);
   }
   // INTERRUPTIBLE_NORESTART_VM returns res == OS_INTRPT for thread.Interrupt
 
