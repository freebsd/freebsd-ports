--- common/plugins/effects/custom/freeverb_effect.cpp.orig	Sun Oct 26 05:07:38 2003
+++ common/plugins/effects/custom/freeverb_effect.cpp	Thu Oct 30 12:00:43 2003
@@ -14,6 +14,11 @@
 
 #define REVERB_SOFT_BITS 16
 
+#if defined(__FreeBSD__)
+  #define lrint(flt)	((int) (flt))
+  #define lrintf(flt)	((int) (flt))
+#endif
+
 void Freeverb_Effect::check_params_changed() {
 
 	if (
