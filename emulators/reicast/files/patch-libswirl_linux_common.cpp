--- libswirl/linux/common.cpp.orig	2020-08-21 20:26:50 UTC
+++ libswirl/linux/common.cpp
@@ -22,6 +22,12 @@
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
@@ -33,7 +39,7 @@
 #include <sys/param.h>
 #include <sys/mman.h>
 #include <sys/time.h>
-#if !defined(TARGET_BSD) && !defined(TARGET_IPHONE) && !defined(TARGET_NACL32) && !defined(TARGET_EMSCRIPTEN) && !defined(TARGET_OSX) && !defined(TARGET_OSX_X64)
+#if !defined(__FreeBSD__) && !defined(TARGET_BSD) && !defined(TARGET_IPHONE) && !defined(TARGET_NACL32) && !defined(TARGET_EMSCRIPTEN) && !defined(TARGET_OSX) && !defined(TARGET_OSX_X64)
   #include <sys/personality.h>
   #include <dlfcn.h>
 #endif
@@ -294,7 +300,7 @@ void enable_runfast()
 }
 
 void linux_fix_personality() {
-    #if !defined(TARGET_BSD) && !defined(_ANDROID) && !defined(TARGET_OS_MAC) && !defined(TARGET_NACL32) && !defined(TARGET_EMSCRIPTEN)
+    #if !defined(__FreeBSD__) && !defined(TARGET_BSD) && !defined(_ANDROID) && !defined(TARGET_OS_MAC) && !defined(TARGET_NACL32) && !defined(TARGET_EMSCRIPTEN)
         printf("Personality: %08X\n", personality(0xFFFFFFFF));
         personality(~READ_IMPLIES_EXEC & personality(0xFFFFFFFF));
         printf("Updated personality: %08X\n", personality(0xFFFFFFFF));
@@ -302,7 +308,7 @@ void linux_fix_personality() {
 }
 
 void linux_rpi2_init() {
-#if !defined(TARGET_BSD) && !defined(_ANDROID) && !defined(TARGET_NACL32) && !defined(TARGET_EMSCRIPTEN) && defined(TARGET_VIDEOCORE)
+#if !defined(__FreeBSD__) && !defined(TARGET_BSD) && !defined(_ANDROID) && !defined(TARGET_NACL32) && !defined(TARGET_EMSCRIPTEN) && defined(TARGET_VIDEOCORE)
 	void* handle;
 	void (*rpi_bcm_init)(void);
 
