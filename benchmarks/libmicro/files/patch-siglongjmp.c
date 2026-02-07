--- siglongjmp.c.orig	2011-05-11 00:58:23 UTC
+++ siglongjmp.c
@@ -56,7 +56,7 @@ benchmark(void *tsd, result_t *res)
 {
 	tsd_t			*ts = (tsd_t *)tsd;
 
-	int i = 0;
+	volatile int i = 0;
 
 	(void) sigsetjmp(ts->ts_env, 1);
 
