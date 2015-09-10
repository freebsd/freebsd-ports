--- io.c.orig	2015-08-20 10:26:38 UTC
+++ io.c
@@ -1123,7 +1123,7 @@ io_test_in(struct k8048 *k, int t1, int 
 
 	if (k->debug >= 10) {
 		fprintf(stderr, "%s(k, t1=%d, t2=%d, %p)\n",
-			__func__, t1, t2, byte);
+			__func__, t1, t2, (void*)byte);
 	}
 
 	/* Get start bit */
