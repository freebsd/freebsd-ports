--- common/plugins/effects/ladspa/ladspa_effect_source.cpp.orig	Fri Oct 24 12:47:05 2003
+++ common/plugins/effects/ladspa/ladspa_effect_source.cpp	Wed Oct 29 22:14:50 2003
@@ -16,6 +16,7 @@
 #include <sys/types.h>
 #include <dirent.h>
 #include <dlfcn.h>
+#include <algorithm>
 
 
 int LADSPA_Effect_Source::get_effect_count() {
