--- player/snd_gm.c.orig	2016-10-03 07:37:10 UTC
+++ player/snd_gm.c
@@ -33,6 +33,7 @@
 #include "snd_gm.h"
 
 #include <math.h> // for log and log2
+#include <tgmath.h>
 #if !defined(HAVE_LOG2) && !defined(__USE_ISOC99) && !defined(log2)
 static double log2(double d)
 {
