--- src/ui/main.c.orig	2004-12-03 07:05:59 UTC
+++ src/ui/main.c
@@ -11,11 +11,10 @@
 #include "ui-main.h"
 #include "input-manager.h"
 
-#include <esd.h>
 #include <gtk/gtk.h>
 #include <gst/gst.h>
 #include <bonobo/bonobo-i18n.h>
-#include <glib/gthread.h>
+#include <glib.h>
 #include <libgnomeui/gnome-ui-init.h>
 
 #include <math.h>
