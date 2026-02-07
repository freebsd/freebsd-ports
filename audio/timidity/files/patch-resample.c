--- resample.c.orig	1996-05-20 13:09:47 UTC
+++ resample.c
@@ -22,7 +22,11 @@
 
 #include <math.h>
 #include <stdio.h>
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #include "config.h"
 #include "common.h"
