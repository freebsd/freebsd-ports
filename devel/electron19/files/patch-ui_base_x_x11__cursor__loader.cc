--- ui/base/x/x11_cursor_loader.cc.orig	2022-05-25 04:01:57 UTC
+++ ui/base/x/x11_cursor_loader.cc
@@ -136,7 +136,11 @@ std::string CursorPathFromLibXcursor() {
     void operator()(void* ptr) const { dlclose(ptr); }
   };
 
+#if defined(OS_BSD)
+  std::unique_ptr<void, DlCloser> lib(dlopen("libXcursor.so", RTLD_LAZY));
+#else
   std::unique_ptr<void, DlCloser> lib(dlopen("libXcursor.so.1", RTLD_LAZY));
+#endif
   if (!lib)
     return "";
 
