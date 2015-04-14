--- devel/rubygem-cool.io/files/patch-ext__libev__ev.c	(revision 0)
+++ devel/rubygem-cool.io/files/patch-ext__libev__ev.c	(working copy)
@@ -0,0 +1,18 @@ 
+--- ext/libev/ev.c.orig	2015-02-24 21:12:24.501215000 +0100
++++ ext/libev/ev.c	2015-02-24 21:16:08.576108000 +0100
+@@ -967,12 +967,12 @@
+   }
+ #endif
+ 
+-#if ECB_GCC_VERSION(4,5)
++#if ECB_GCC_VERSION(4,5) || defined __clang__
+   #define ecb_unreachable() __builtin_unreachable ()
+ #else
+   /* this seems to work fine, but gcc always emits a warning for it :/ */
+-  ecb_inline void ecb_unreachable (void) ecb_noreturn;
+-  ecb_inline void ecb_unreachable (void) { }
++  ecb_inline void ecb_noreturn ecb_unreachable (void);
++  ecb_inline void ecb_noreturn ecb_unreachable (void) { }
+ #endif
+ 
+ /* try to tell the compiler that some condition is definitely true */
