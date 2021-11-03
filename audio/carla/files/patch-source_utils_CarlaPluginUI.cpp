--- source/utils/CarlaPluginUI.cpp.orig	2021-11-03 18:15:18 UTC
+++ source/utils/CarlaPluginUI.cpp
@@ -19,6 +19,7 @@
 #include "CarlaPluginUI.hpp"
 
 #ifdef HAVE_X11
+# include <pthread.h>
 # include <sys/types.h>
 # include <X11/Xatom.h>
 # include <X11/Xlib.h>
