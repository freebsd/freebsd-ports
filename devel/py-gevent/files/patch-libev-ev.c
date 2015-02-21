--- libev/ev.c.orig	2014-04-30 16:45:07.000000000 +0200
+++ libev/ev.c	2015-02-20 23:33:36.945803000 +0100
@@ -967,8 +967,8 @@
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
-  ecb_inline void ecb_unreachable (void) ecb_noreturn;
-  ecb_inline void ecb_unreachable (void) { }
+  ecb_inline ecb_noreturn void ecb_unreachable (void);
+  ecb_inline ecb_noreturn void ecb_unreachable (void) { }
 #endif
 
 /* try to tell the compiler that some condition is definitely true */
