--- mix.c.orig	1996-05-20 13:09:46 UTC
+++ mix.c
@@ -23,7 +23,11 @@
 
 #include <math.h>
 #include <stdio.h>
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #include "config.h"
 #include "common.h"
