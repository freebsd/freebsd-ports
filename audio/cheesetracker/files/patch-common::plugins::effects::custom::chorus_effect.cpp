--- common/plugins/effects/custom/chorus_effect.cpp.orig	Sun Oct 26 05:07:38 2003
+++ common/plugins/effects/custom/chorus_effect.cpp	Thu Oct 30 12:00:04 2003
@@ -10,10 +10,16 @@
 //
 //
 #include "chorus_effect.h"
+#include <math.h>
 
 
 #define FRACTIONAL_BITS 13
 #define MIX_CALCULATE_INCREMENT_INTERVAL 8
+
+#if defined(__FreeBSD__)
+  #define lrint(flt)	((int) (flt))
+  #define lrintf(flt)	((int) (flt))
+#endif
 
 
 inline static double get_msecs_from_samples(double p_samples,double p_mixfreq) {
