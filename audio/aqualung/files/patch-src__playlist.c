--- ./src/playlist.c.orig	Mon Feb  5 00:46:43 2007
+++ ./src/playlist.c	Mon Feb  5 00:47:06 2007
@@ -51,6 +51,8 @@
 #include "playlist.h"
 #include "ifp_device.h"
 
+#include <strfunc.h>
+
 extern options_t options;
 
 extern void assign_audio_fc_filters(GtkFileChooser *fc);
