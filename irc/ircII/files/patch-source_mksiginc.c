--- source/mksiginc.c.orig	2004-02-16 01:00:58.000000000 -0900
+++ source/mksiginc.c	2008-02-14 00:14:47.000000000 -0900
@@ -38,8 +38,11 @@
 #ifndef NSIG
 #define NSIG 64
 #endif
-
+#if defined(SIGRTMAX) && (SIGRTMAX > NSIG)
+#define MAXSIG SIGRTMAX+1
+#else
 #define MAXSIG NSIG+1
+#endif
 char *signames[MAXSIG];
 
 int main(int, char *[], char *[]);
