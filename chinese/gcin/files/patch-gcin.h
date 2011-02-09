--- gcin.h.bak	2010-06-18 08:54:14.000000000 +0800
+++ gcin.h	2011-02-08 12:13:27.000000000 +0800
@@ -50,6 +50,14 @@
 #define GTK_WIDGET_REALIZED gtk_widget_get_realized
 #endif
 
+#if GTK_CHECK_VERSION(2, 22, 0)
+#define GDK_DISPLAY() (GDK_DISPLAY_XDISPLAY(gdk_display_get_default()))
+#endif
+
+#ifndef GTK_API_VERSION_2
+#define GDK_DISPLAY() (GDK_DISPLAY_XDISPLAY(gdk_display_get_default()))
+#endif
+
 typedef enum {
   GCIN_STATE_DISABLED = 0,
   GCIN_STATE_ENG_FULL = 1,
