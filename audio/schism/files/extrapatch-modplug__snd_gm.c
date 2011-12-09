--- ./modplug/snd_gm.c.orig	2010-01-01 20:22:26.000000000 +0100
+++ ./modplug/snd_gm.c	2011-12-09 21:50:22.000000000 +0100
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
