--- main.c.orig	2011-05-06 12:27:59.000000000 +0000
+++ main.c	2011-05-08 11:25:32.000000000 +0000
@@ -34,6 +34,8 @@
 #include "awk.h"
 #include "ytab.h"
 
+#include <fenv.h>
+
 extern	char	**environ;
 extern	int	nfields;
 
@@ -68,6 +70,7 @@
 		exit(1);
 	}
 	signal(SIGFPE, fpecatch);
+	feenableexcept(FE_DIVBYZERO|FE_INEXACT|FE_OVERFLOW);
 
 	srand_seed = 1;
 	srand(srand_seed);
