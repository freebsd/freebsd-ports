--- modplug/snd_gm.c.orig	2010-01-01 19:22:26 UTC
+++ modplug/snd_gm.c
@@ -10,12 +10,14 @@
 #include "mplink.h" // for 'mp', which we shouldn't need
 #include "snd_gm.h"
 
+/*
 #if !defined(HAVE_LOG2) && !defined(__USE_ISOC99) && !defined(log2)
 static double log2(double d)
 {
         return log(d) / log(2.0);
 }
 #endif
+*/
 
 
 #define LinearMidivol 1
