--- lib/mem.c.orig	1997-01-25 18:11:55.000000000 +0900
+++ lib/mem.c	2012-05-10 00:14:28.835551865 +0900
@@ -44,6 +44,7 @@
 	return(_rval);
 }
 
+#if 0
 void	wzero(void *head, int n)
 {
 	__asm__	("cld\n\t"
@@ -76,11 +77,5 @@
 		"S" ((long)src)
 		:"cx","di","si");
 }
+#endif
 
-void	SafeFree(void **p)
-{
-	if (*p) {
-		free(*p);
-		*p = NULL;
-	}
-}
