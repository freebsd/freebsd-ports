--- longjmp.c.orig	Wed Aug 31 11:53:48 2005
+++ longjmp.c	Wed Aug 31 11:55:10 2005
@@ -55,7 +55,7 @@
 int
 benchmark(void *tsd, result_t *res)
 {
-	int			i = 0;
+	volatile int		i = 0;
 	jmp_buf			env;
 
 	(void) setjmp(env);
