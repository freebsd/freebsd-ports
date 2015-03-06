--- ext/libev/ev.c.orig	2015-02-24 21:22:11.038934000 +0100
+++ ext/libev/ev.c	2015-02-24 21:23:03.298987000 +0100
@@ -1026,12 +1026,12 @@
   }
 #endif
 
-#if ECB_GCC_VERSION(4,5)
+#if ECB_GCC_VERSION(4,5) || defined __clang__
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
-  ecb_inline void ecb_unreachable (void) ecb_noreturn;
-  ecb_inline void ecb_unreachable (void) { }
+  ecb_inline void ecb_noreturn ecb_unreachable (void);
+  ecb_inline void ecb_noreturn ecb_unreachable (void) { }
 #endif
 
 /* try to tell the compiler that some condition is definitely true */
