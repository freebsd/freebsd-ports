--- ui/gtk/gtk_compat.cc.orig	2025-07-04 05:17:07 UTC
+++ ui/gtk/gtk_compat.cc
@@ -65,22 +65,38 @@ void* GetLibGio() {
 }
 
 void* GetLibGio() {
+#if BUILDFLAG(IS_BSD)
+  static void* libgio = DlOpen("libgio-2.0.so");
+#else
   static void* libgio = DlOpen("libgio-2.0.so.0");
+#endif
   return libgio;
 }
 
 void* GetLibGdk3() {
+#if BUILDFLAG(IS_BSD)
+  static void* libgdk3 = DlOpen("libgdk-3.so");
+#else
   static void* libgdk3 = DlOpen("libgdk-3.so.0");
+#endif
   return libgdk3;
 }
 
 void* GetLibGtk3(bool check = true) {
+#if BUILDFLAG(IS_BSD)
+  static void* libgtk3 = DlOpen("libgtk-3.so", check);
+#else
   static void* libgtk3 = DlOpen("libgtk-3.so.0", check);
+#endif
   return libgtk3;
 }
 
 void* GetLibGtk4(bool check = true) {
+#if BUILDFLAG(IS_BSD)
+  static void* libgtk4 = DlOpen("libgtk-4.so", check);
+#else
   static void* libgtk4 = DlOpen("libgtk-4.so.1", check);
+#endif
   return libgtk4;
 }
 
@@ -165,7 +181,11 @@ void* GetLibGdkPixbuf() {
 }  // namespace
 
 void* GetLibGdkPixbuf() {
+#if BUILDFLAG(IS_BSD)
+  static void* libgdk_pixbuf = DlOpen("libgdk_pixbuf-2.0.so");
+#else
   static void* libgdk_pixbuf = DlOpen("libgdk_pixbuf-2.0.so.0");
+#endif
   return libgdk_pixbuf;
 }
 
