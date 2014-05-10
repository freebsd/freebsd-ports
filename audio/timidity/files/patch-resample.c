--- ./resample.c.orig	1996-05-20 08:09:47.000000000 -0500
+++ ./resample.c	2013-04-21 10:18:23.000000000 -0500
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
