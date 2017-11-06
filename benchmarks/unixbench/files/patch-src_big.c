--- src/big.c.orig	2015-06-04 17:20:18 UTC
+++ src/big.c
@@ -583,7 +583,7 @@ void dumpwork(void)
 void fatal(char *s)
 {
     int	i;
-    fprintf(stderr, s);
+    fprintf(stderr, "%s", s);
     fflush(stderr);
     perror("Reason?");
     fflush(stderr);
