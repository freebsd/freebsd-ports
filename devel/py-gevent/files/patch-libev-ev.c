--- libev/ev.c.orig	2015-05-23 12:04:13 UTC
+++ libev/ev.c
@@ -1026,8 +1026,8 @@ ecb_inline uint64_t ecb_rotr64 (uint64_t
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
-  ecb_inline void ecb_unreachable (void) ecb_noreturn;
-  ecb_inline void ecb_unreachable (void) { }
+  ecb_inline ecb_noreturn void ecb_unreachable (void);
+  ecb_inline ecb_noreturn void ecb_unreachable (void) { }
 #endif
 
 /* try to tell the compiler that some condition is definitely true */
