--- ../rscpp/cpp.h.orig	Fri Mar  1 00:15:54 2002
+++ ../rscpp/cpp.h	Fri Mar  1 00:15:56 2002
@@ -462,7 +462,9 @@
 extern char     *strrchr();
 extern char     *strchr();
 #if ! ( defined UNX && defined ALPHA )
+#if ! ( defined FREEBSD )
 extern long     time();
+#endif
 #endif
 /* extern char     *sprintf();  */           /* Lint needs this              */
 
