--- source/mksiginc.c.orig	2011-07-05 19:26:18.000000000 -0400
+++ source/mksiginc.c	2011-07-05 19:27:39.000000000 -0400
@@ -39,7 +39,11 @@ IRCII_RCSID("@(#)$eterna: mksiginc.c,v 1
 #define NSIG 64
 #endif
 
+#if defined(SIGRTMAX) && (SIGRTMAX > NSIG)
+#define MY_MAXSIG SIGRTMAX+1
+#else
 #define MY_MAXSIG NSIG+1
+#endif
 char *signames[MY_MAXSIG];
 
 int main(int, char *[], char *[]);
