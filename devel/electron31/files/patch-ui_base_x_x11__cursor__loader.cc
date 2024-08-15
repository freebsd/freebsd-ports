--- ui/base/x/x11_cursor_loader.cc.orig	2024-06-18 21:44:02 UTC
+++ ui/base/x/x11_cursor_loader.cc
@@ -33,7 +33,7 @@
 #include "ui/gfx/x/connection.h"
 #include "ui/gfx/x/xproto.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -139,7 +139,11 @@ std::string CursorPathFromLibXcursor() {
     void operator()(void* ptr) const { dlclose(ptr); }
   };
 
+#if BUILDFLAG(IS_BSD)
+  std::unique_ptr<void, DlCloser> lib(dlopen("libXcursor.so", RTLD_LAZY));
+#else
   std::unique_ptr<void, DlCloser> lib(dlopen("libXcursor.so.1", RTLD_LAZY));
+#endif
   if (!lib)
     return "";
 
@@ -250,7 +254,7 @@ scoped_refptr<base::RefCountedMemory> ReadCursorFile(
     const std::string& rm_xcursor_theme) {
   constexpr const char kDefaultTheme[] = "default";
   std::string themes[] = {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // The toolkit theme has the highest priority.
     LinuxUi::instance() ? LinuxUi::instance()->GetCursorThemeName()
                         : std::string(),
@@ -442,7 +446,7 @@ uint32_t XCursorLoader::GetPreferredCursorSize() const
     return size;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Let the toolkit have the next say.
   auto* linux_ui = LinuxUi::instance();
   size = linux_ui ? linux_ui->GetCursorThemeSize() : 0;
