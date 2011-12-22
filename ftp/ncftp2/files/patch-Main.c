--- Main.c.orig	1998-03-20 11:21:09.000000000 +0800
+++ Main.c	2011-12-22 00:11:54.000000000 +0800
@@ -19,6 +19,9 @@
 #include <pwd.h>
 #include <errno.h>
 #include <ctype.h>
+#ifdef __FreeBSD__
+#include <locale.h>
+#endif
 #include <signal.h>
 #include <setjmp.h>
 #include <stdlib.h>
@@ -872,11 +875,14 @@ SigIntMain(/* int sigNum */ void)
 
 
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
 	int opt, result;
 	OpenOptions openopt;
 
+#ifdef __FreeBSD__
+	setlocale(LC_ALL, "");
+#endif
 	Init();
 	RunStartupScript();
 
