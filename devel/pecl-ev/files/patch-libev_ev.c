--- libev/ev.c.orig	2015-11-29 14:37:29 UTC
+++ libev/ev.c
@@ -1010,7 +1010,7 @@ ecb_inline uint64_t ecb_rotr64 (uint64_t
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
-  ecb_inline void ecb_unreachable (void) ecb_noreturn;
+  ecb_noreturn ecb_inline void ecb_unreachable (void);
   ecb_inline void ecb_unreachable (void) { }
 #endif
 
