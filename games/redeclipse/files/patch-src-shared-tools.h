--- src/shared/tools.h.orig	2009-04-26 00:14:34.000000000 +0400
+++ src/shared/tools.h	2009-05-07 19:45:42.000000000 +0400
@@ -764,6 +764,12 @@
 template<class T> inline void bigswap(T *buf, int len) { if(*(const uchar *)&islittleendian) endianswap(buf, len); }
 #endif
 
+#ifdef getchar
+#undef getchar
+#endif
+#ifdef putchar
+#undef putchar
+#endif
 struct stream
 {
     virtual ~stream() {}
