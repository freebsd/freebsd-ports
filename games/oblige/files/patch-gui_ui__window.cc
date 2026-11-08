--- gui/ui_window.cc.orig	2017-08-06 03:12:11 UTC
+++ gui/ui_window.cc
@@ -27,11 +27,6 @@
 #include <unistd.h>
 #endif
 
-#if (FL_MAJOR_VERSION != 1 ||  \
-	 FL_MINOR_VERSION != 3 ||  \
-	 FL_PATCH_VERSION < 0)
-#error "Require FLTK version 1.3.0 or later"
-#endif
 
 
 #define BASE_WINDOW_W  816
