--- src/cvs.h.orig	Fri Jan 23 18:47:11 2004
+++ src/cvs.h	Fri Jan 23 18:48:21 2004
@@ -931,6 +931,9 @@
 /* stdio redirection, the easy way... */
 #include <stdio.h>
 #define printf cvs_printf
+#if defined(putchar)
+#undef putchar
+#endif
 #define putchar cvs_putchar
 #define puts cvs_puts
 #define fputs cvs_fputs
@@ -982,7 +985,7 @@
 
 #ifndef __USER_HANDLE_T_DEFINED
 /* User handle pointer */
-typedef struct { void *__unused; } *user_handle_t;
+typedef struct { void *_unused; } *user_handle_t;
 #define __USER_HANDLE_T_DEFINED
 #endif
 
