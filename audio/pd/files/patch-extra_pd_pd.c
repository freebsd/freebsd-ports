--- extra/pd~/pd~.c.orig	2008-12-12 01:29:02.000000000 +0900
+++ extra/pd~/pd~.c	2009-01-12 01:36:46.000000000 +0900
@@ -11,6 +11,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <ctype.h>
+#include <signal.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
@@ -47,7 +48,7 @@
 
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #ifdef __x86_64__
 static char pd_tilde_dllextent[] = ".l_ia64",
     pd_tilde_dllextent2[] = ".pd_linux";
