--- Ma2Asm/ix86_any.c.orig	Sat Jun 30 12:19:37 2001
+++ Ma2Asm/ix86_any.c	Sat Jun 30 12:20:04 2001
@@ -39,7 +39,7 @@
 
 #define MAX_C_ARGS_IN_C_CODE       32
 
-#if defined(M_ix86_cygwin) || defined(M_ix86_bsd)
+#if defined(M_ix86_cygwin) || (defined(M_ix86_bsd) && !defined(__FreeBSD__))
 
 #define UN                         "_"
 
