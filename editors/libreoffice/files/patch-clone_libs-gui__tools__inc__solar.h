--- clone/libs-gui/tools/inc/tools/solar.h.orig	2011-08-25 22:53:01.311106000 +0200
+++ clone/libs-gui/tools/inc/tools/solar.h	2011-08-25 22:53:36.335015661 +0200
@@ -267,10 +267,8 @@
   #define __DLLEXTENSION "lh.so"
 #elif defined LINUX && defined AXP
   #define __DLLEXTENSION "ll.so"
-#elif defined FREEBSD && defined X86
-  #define __DLLEXTENSION "fi.so"
-#elif defined FREEBSD && defined X86_64
-  #define __DLLEXTENSION "fx.so"
+#elif defined FREEBSD
+  #define __DLLEXTENSION "fb.so"
 #elif defined MACOSX && defined POWERPC
   #define __DLLEXTENSION "mxp.dylib"
 #elif defined MACOSX && defined X86
