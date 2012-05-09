--- include/mem.h.orig	1997-01-24 16:06:22.000000000 +0900
+++ include/mem.h	2012-05-10 00:14:28.759551808 +0900
@@ -46,6 +46,7 @@
 	     "d" ((u_short) port));
 }
 
+#if 0
 static inline
     void lzero(void *head, int n)
 {
@@ -93,11 +94,22 @@
 	     "D" ((long)head)
 	     :"cx","di");
 }
+#endif
 
 extern u_char PortInb(u_short);
+#if 1
+#define bzero(b, len) bzero(b, len)
+#define bzero2(b, len) bzero(b, len)
+#define lzero(b, len) bzero(b, len)
+#define wzero(b, len) bzero(b, len)
+#define bmove(dst, src, len) bcopy(src, dst, len)
+#define brmove(dst, src, len) bcopy(src, dst, len)
+#define wmove(dst, src, len) bcopy(src, dst, len)
+#define lmove(dst, src, len) bcopy(src, dst, len)
+#else
 extern void wzero(void *, int);
 extern void wmove(void *, void *, int);
 extern void lmove(void *, void *, int);
-extern void SafeFree(void **);
+#endif
 
 #endif
