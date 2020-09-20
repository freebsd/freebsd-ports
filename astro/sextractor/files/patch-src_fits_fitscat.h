--- src/fits/fitscat.h.orig	2006-07-10 13:17:06 UTC
+++ src/fits/fitscat.h
@@ -306,7 +306,14 @@ extern  void	error(int, char *, char *),
 		swapbytes(void *ptr, int nb, int n),
 		warning(char *msg1, char *msg2);
 
+#ifdef IN_MAIN
+#define EXTERN
+#warning IN_MAIN
+#else
+#define EXTERN extern
+#warning NOT_IN_MAIN
+#endif
 
-int		bswapflag;
+EXTERN int	bswapflag;
 
 #endif
