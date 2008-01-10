
$FreeBSD$

--- src/paprefs.cc.orig
+++ src/paprefs.cc
@@ -28,6 +28,7 @@
 #include <gtkmm.h>
 #include <libglademm.h>
 #include <gconfmm.h>
+#include <libintl.h>
 
 #define PA_GCONF_ROOT "/system/pulseaudio"
 #define PA_GCONF_PATH_MODULES PA_GCONF_ROOT"/modules"
