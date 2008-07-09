--- qe.h.orig	2003-04-22 00:01:42.000000000 +0200
+++ qe.h	2005-06-07 16:02:27.000000000 +0200
@@ -576,10 +576,18 @@
 
 /* make sure that the keyword is not disabled by glibc (TINYC case) */
 #undef __attribute__ 
-
+#if __GNUC__ < 3 || (__GNUC__ == 3 && __GNUC_MINOR__ < 3)
 /* same method as the linux kernel... */
 #define __init_call	__attribute__ ((unused,__section__ (".initcall.init")))
 #define __exit_call	__attribute__ ((unused,__section__ (".exitcall.exit")))
+#else
+#undef __attribute_used__
+#define __attribute_used__	__attribute__((__used__))
+#define __init_call	__attribute_used__ __attribute__((__section__ (".initcall.init")))
+#define __exit_call	__attribute_used__ __attribute__((__section__ (".exitcall.exit")))
+
+#endif
+
 
 #define qe_module_init(fn) \
 	static int (*__initcall_##fn)(void) __init_call = fn
