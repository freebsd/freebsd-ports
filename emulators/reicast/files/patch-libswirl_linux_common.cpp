--- libswirl/linux/common.cpp.orig	2020-10-18 11:22:48 UTC
+++ libswirl/linux/common.cpp
@@ -9,7 +9,7 @@
 
 #include <pthread.h>
 
-#if HOST_OS==OS_LINUX || HOST_OS == OS_DARWIN
+#if HOST_OS==OS_LINUX || HOST_OS == OS_DARWIN || HOST_OS == OS_FREEBSD
 
 #if HOST_OS == OS_DARWIN
 	#define _XOPEN_SOURCE 1
@@ -17,11 +17,20 @@
 	#include <TargetConditionals.h>
     #include <dlfcn.h>
     #include <util.h>
+#elif HOST_OS == OS_FREEBSD
+    #include <dlfcn.h>
+    #include <libutil.h>
 #endif
 #if FEAT_HAS_SERIAL_TTY
     #include <sys/stat.h>
     #if HOST_OS == OS_DARWIN
         #import <util.h>
+    #elif defined(__FreeBSD__)
+        #include <dlfcn.h>
+        #include <sys/types.h>
+        #include <sys/ioctl.h>
+        #include <termios.h>
+        #include <libutil.h>
     #else
         #include <pty.h>
     #endif
@@ -33,7 +42,7 @@
 #include <sys/param.h>
 #include <sys/mman.h>
 #include <sys/time.h>
-#if !defined(TARGET_BSD) && !defined(TARGET_IPHONE) && !defined(TARGET_NACL32) && !defined(TARGET_EMSCRIPTEN) && !defined(TARGET_OSX) && !defined(TARGET_OSX_X64)
+#if !defined(__FreeBSD__) && !defined(TARGET_BSD) && !defined(TARGET_IPHONE) && !defined(TARGET_NACL32) && !defined(TARGET_EMSCRIPTEN) && !defined(TARGET_OSX) && !defined(TARGET_OSX_X64)
   #include <sys/personality.h>
   #include <dlfcn.h>
 #endif
@@ -294,7 +303,7 @@ void enable_runfast()
 }
 
 void linux_fix_personality() {
-    #if !defined(TARGET_BSD) && !defined(_ANDROID) && !defined(TARGET_OS_MAC) && !defined(TARGET_NACL32) && !defined(TARGET_EMSCRIPTEN)
+    #if !defined(__FreeBSD__) && !defined(TARGET_BSD) && !defined(_ANDROID) && !defined(TARGET_OS_MAC) && !defined(TARGET_NACL32) && !defined(TARGET_EMSCRIPTEN)
         printf("Personality: %08X\n", personality(0xFFFFFFFF));
         personality(~READ_IMPLIES_EXEC & personality(0xFFFFFFFF));
         printf("Updated personality: %08X\n", personality(0xFFFFFFFF));
@@ -302,7 +311,7 @@ void linux_fix_personality() {
 }
 
 void linux_rpi2_init() {
-#if !defined(TARGET_BSD) && !defined(_ANDROID) && !defined(TARGET_NACL32) && !defined(TARGET_EMSCRIPTEN) && defined(TARGET_VIDEOCORE)
+#if !defined(__FreeBSD__) && !defined(TARGET_BSD) && !defined(_ANDROID) && !defined(TARGET_NACL32) && !defined(TARGET_EMSCRIPTEN) && defined(TARGET_VIDEOCORE)
 	void* handle;
 	void (*rpi_bcm_init)(void);
 
