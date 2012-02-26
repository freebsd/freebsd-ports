--- src/support/widgets/gtkxine.h.orig	Sat Nov 23 22:56:41 2002
+++ src/support/widgets/gtkxine.h	Sat Dec  7 15:09:28 2002
@@ -20,6 +20,7 @@
 
 #ifdef ENABLE_XINE
 
+#include <pthread.h>
 #include <X11/X.h>
 #include <X11/Xlib.h>
 #include <X11/extensions/XShm.h>
@@ -56,8 +57,13 @@ extern          "C"
 	xine_event_queue_t *event_queue;
 
 	char            configfile[256];
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 	xine_vo_driver_t *vo_driver;
 	xine_ao_driver_t *ao_driver;
+#else
+	xine_video_port_t *vo_driver;
+	xine_audio_port_t *ao_driver;
+#endif
 	x11_visual_t    vis;
 	double          display_ratio;
 	Display        *display;
