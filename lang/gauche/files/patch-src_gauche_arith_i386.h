--- src/gauche/arith_i386.h.orig	Sat Jul  5 11:29:13 2003
+++ src/gauche/arith_i386.h	Sun Dec  5 23:19:45 2004
@@ -167,6 +167,7 @@
  *  else r <- x * y, v = 0
  */
 
+#if 0
 #define UMULOV(r, v, x, y) \
     asm("movl %2, %%eax;" \
         "mull %3;" \
@@ -199,6 +200,8 @@
            :"=r" (r), "=&r" (v) \
            :"g" (x), "r" (y) \
            :"%eax", "%edx")
+
+#endif
 
 #endif /*__GNUC__*/
 
