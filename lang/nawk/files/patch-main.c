--- main.c.orig	2007-05-01 16:05:28.000000000 -0500
+++ main.c	2008-07-08 15:33:37.000000000 -0500
@@ -34,6 +34,8 @@
 #include "awk.h"
 #include "ytab.h"
 
+#include <fenv.h>
+
 extern	char	**environ;
 extern	int	nfields;
 
@@ -67,6 +69,7 @@
 		exit(1);
 	}
 	signal(SIGFPE, fpecatch);
+	feenableexcept(FE_DIVBYZERO|FE_INEXACT|FE_OVERFLOW);
 	yyin = NULL;
 	symtab = makesymtab(NSYMTAB/NSYMTAB);
 	while (argc > 1 && argv[1][0] == '-' && argv[1][1] != '\0') {
