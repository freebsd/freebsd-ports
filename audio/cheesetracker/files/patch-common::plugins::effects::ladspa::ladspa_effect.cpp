--- common/plugins/effects/ladspa/ladspa_effect.cpp.orig	Sun Oct 26 05:07:38 2003
+++ common/plugins/effects/ladspa/ladspa_effect.cpp	Thu Oct 30 12:01:23 2003
@@ -18,6 +18,11 @@
 #include <dirent.h>
 #include <dlfcn.h>
 
+#if defined(__FreeBSD__)
+  #define lrint(flt)	((int) (flt))
+  #define lrintf(flt)	((int) (flt))
+#endif
+
 
 void LADSPA_Effect::reset() {
 
