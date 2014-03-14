--- Eris/iround.h.orig	2014-03-04 15:26:04.000000000 +0100
+++ Eris/iround.h	2014-03-04 16:16:31.000000000 +0100
@@ -12,8 +12,8 @@
 #define L_ROUND(_x) (boost::math::llround(_x))
 #else
 #include <cmath>
-#define I_ROUND(_x) (std::lround(_x))
-#define L_ROUND(_x) (std::llround(_x))
+#define I_ROUND(_x) (lround(_x))
+#define L_ROUND(_x) (llround(_x))
 #endif
 
 #endif // ERIS_IROUND_H
