--- ./src/callbacks.h.orig	2004-09-27 20:13:40.000000000 +0000
+++ ./src/callbacks.h	2012-09-18 15:29:36.555081225 +0000
@@ -1,5 +1,8 @@
 #include <gnome.h>
 
+#ifdef __FreeBSD__
+#define USE_PPI_DEV
+#endif
 
 void
 on_new1_activate                       (GtkMenuItem     *menuitem,
