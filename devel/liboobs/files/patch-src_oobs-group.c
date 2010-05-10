--- oobs/oobs-group.c.orig	2010-01-11 13:34:52.000000000 -0500
+++ oobs/oobs-group.c	2010-01-18 02:04:34.000000000 -0500
@@ -21,6 +21,7 @@
 
 #include <string.h>
 #include <glib-object.h>
+#include <unistd.h>
 #include <dbus/dbus.h>
 
 #include "oobs-object-private.h"
