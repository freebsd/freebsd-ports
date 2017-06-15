--- libeio/ecb.h.orig	2016-07-24 19:02:19.000000000 +0200
+++ libeio/ecb.h	2016-12-26 10:31:13.000232000 +0100
@@ -452,12 +452,12 @@
   }
 #endif
 
-#if ECB_GCC_VERSION(4,5)
+#if ECB_GCC_VERSION(4,5) || defined __clang__
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
   ecb_noreturn ecb_inline void ecb_unreachable (void);
-  ecb_inline void ecb_unreachable (void) { }
+  ecb_noreturn ecb_inline void ecb_unreachable (void) { }
 #endif
 
 /* try to tell the compiler that some condition is definitely true */
