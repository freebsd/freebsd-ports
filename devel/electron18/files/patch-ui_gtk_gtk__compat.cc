--- ui/gtk/gtk_compat.cc.orig	2022-06-23 06:01:33 UTC
+++ ui/gtk/gtk_compat.cc
@@ -62,22 +62,38 @@ auto DlCast(void* symbol) {
 }
 
 void* GetLibGio() {
+#if defined(OS_BSD)
+  static void* libgio = DlOpen("libgio-2.0.so");
+#else
   static void* libgio = DlOpen("libgio-2.0.so.0");
+#endif
   return libgio;
 }
 
 void* GetLibGdk3() {
+#if defined(OS_BSD)
+  static void* libgdk3 = DlOpen("libgdk-3.so");
+#else
   static void* libgdk3 = DlOpen("libgdk-3.so.0");
+#endif
   return libgdk3;
 }
 
 void* GetLibGtk3(bool check = true) {
+#if defined(OS_BSD)
+  static void* libgtk3 = DlOpen("libgtk-3.so", check);
+#else
   static void* libgtk3 = DlOpen("libgtk-3.so.0", check);
+#endif
   return libgtk3;
 }
 
 void* GetLibGtk4(bool check = true) {
+#if defined(OS_BSD)
+  static void* libgtk4 = DlOpen("libgtk-4.so", check);
+#else
   static void* libgtk4 = DlOpen("libgtk-4.so.1", check);
+#endif
   return libgtk4;
 }
 
@@ -123,7 +139,11 @@ gfx::Insets InsetsFromGtkBorder(const GtkBorder& borde
 }  // namespace
 
 void* GetLibGdkPixbuf() {
+#if defined(OS_BSD)
+  static void* libgdk_pixbuf = DlOpen("libgdk_pixbuf-2.0.so");
+#else
   static void* libgdk_pixbuf = DlOpen("libgdk_pixbuf-2.0.so.0");
+#endif
   return libgdk_pixbuf;
 }
 
