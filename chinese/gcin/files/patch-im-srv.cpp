--- im-srv.cpp~	2010-04-09 21:14:55.000000000 +0800
+++ im-srv.cpp	2011-01-29 14:11:47.000000000 +0800
@@ -15,6 +15,8 @@
 #include "gcin.h"
 #include "gcin-protocol.h"
 #include "im-srv.h"
+#include <gtk/gtk.h>
+#include <gdk/gdkx.h>
 #include <gdk/gdk.h>
 
 #if UNIX
