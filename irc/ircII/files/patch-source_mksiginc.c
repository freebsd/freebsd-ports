--- source/mksiginc.c.orig	2014-03-17 20:38:51 UTC
+++ source/mksiginc.c
@@ -35,7 +35,11 @@ IRCII_RCSID("@(#)$eterna: mksiginc.c,v 1
 #define NSIG 64
 #endif
 
+#if defined(SIGRTMAX) && (SIGRTMAX > NSIG)
+#define MY_MAXSIG SIGRTMAX+1
+#else
 #define MY_MAXSIG NSIG+1
+#endif
 char *signames[MY_MAXSIG];
 
 int main(int, char *[]);
