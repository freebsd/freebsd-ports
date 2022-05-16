--- ui/gfx/x/xlib_support.cc.orig	2022-05-11 07:02:11 UTC
+++ ui/gfx/x/xlib_support.cc
@@ -38,10 +38,18 @@ void InitXlib() {
   if (xlib_loader->loaded())
     return;
 
+#if defined(OS_BSD)
+  CHECK(xlib_loader->Load("libX11.so"));
+#else
   CHECK(xlib_loader->Load("libX11.so.6"));
+#endif
 
   auto* xlib_xcb_loader = GetXlibXcbLoader();
+#if defined(OS_BSD)
+  CHECK(xlib_xcb_loader->Load("libX11-xcb.so"));
+#else
   CHECK(xlib_xcb_loader->Load("libX11-xcb.so.1"));
+#endif
 
   CHECK(xlib_loader->XInitThreads());
 
