--- longjmp.c.orig	2011-05-11 00:58:23 UTC
+++ longjmp.c
@@ -51,7 +51,7 @@ benchmark_init()
 int
 benchmark(void *tsd, result_t *res)
 {
-	int			i = 0;
+	volatile int		i = 0;
 	jmp_buf			env;
 
 	(void) setjmp(env);
