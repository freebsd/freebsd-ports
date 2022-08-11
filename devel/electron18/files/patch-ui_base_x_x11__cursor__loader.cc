--- ui/base/x/x11_cursor_loader.cc.orig	2022-05-11 07:17:06 UTC
+++ ui/base/x/x11_cursor_loader.cc
@@ -138,7 +138,11 @@ std::string CursorPathFromLibXcursor() {
     void operator()(void* ptr) const { dlclose(ptr); }
   };
 
+#if defined(OS_BSD)
+  std::unique_ptr<void, DlCloser> lib(dlopen("libXcursor.so", RTLD_LAZY));
+#else
   std::unique_ptr<void, DlCloser> lib(dlopen("libXcursor.so.1", RTLD_LAZY));
+#endif
   if (!lib)
     return "";
 
