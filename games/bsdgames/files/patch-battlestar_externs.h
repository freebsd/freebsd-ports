--- battlestar/externs.h.orig	2012-05-25 11:57:52.000000000 +0200
+++ battlestar/externs.h	2012-05-25 11:57:55.000000000 +0200
@@ -44,15 +44,18 @@
 #include <string.h>
 #include <unistd.h>
 
+/* We use our own */
+#undef setbit
+#undef testbit
+#undef clearbit
+
 #define BITS (8)
 
 #define OUTSIDE		(position > 68 && position < 246 && position != 218)
 #define rnd(x)          (random() % (x))
 #define max(a,b)	((a) < (b) ? (b) : (a))
 #define testbit(array, index)	(array[index/BITS] & (1 << (index % BITS)))
-#ifndef setbit
 #define setbit(array, index)	(array[index/BITS] |= (1 << (index % BITS)))
-#endif
 #define clearbit(array, index)	(array[index/BITS] &= ~(1 << (index % BITS)))
 
 	/* well known rooms */
