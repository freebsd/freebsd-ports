--- src/unix/osinline.h.orig	2006-05-15 18:47:35.000000000 +0200
+++ src/unix/osinline.h	2013-08-28 11:04:54.000000000 +0200
@@ -32,7 +32,7 @@ INLINE int _vec_mult(int x, int y)
 			:  "=&a" (result)           /* the result has to go in eax */
 			:  "mr" (x),                /* x and y can be regs or mem */
 			   "mr" (y)
-			:  "%edx", "%cc"            /* clobbers edx and flags */
+			:  "%edx", "cc"             /* clobbers edx and flags */
 		);
 	return result;
 }
