--- siglongjmp.c.orig	Wed Aug 31 11:53:57 2005
+++ siglongjmp.c	Wed Aug 31 11:55:14 2005
@@ -60,7 +60,7 @@
 {
 	tsd_t			*ts = (tsd_t *)tsd;
 
-	int i = 0;
+	volatile int i = 0;
 
 	(void) sigsetjmp(ts->ts_env, 1);
 
