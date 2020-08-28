--- src/gensktab.c.orig	2020-08-28 17:56:24 UTC
+++ src/gensktab.c
@@ -2,7 +2,7 @@
 #include <stdio.h>
 #include "cpmio.h"
 
-int	skew;
+extern int	skew;
 int	*skewtab;
 
 /*
