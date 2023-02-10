--- ui/base/x/x11_cursor_loader.cc.orig	2022-10-24 13:33:33 UTC
+++ ui/base/x/x11_cursor_loader.cc
@@ -32,7 +32,7 @@
 #include "ui/gfx/x/xproto.h"
 #include "ui/gfx/x/xproto_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
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
 
@@ -249,7 +253,7 @@ scoped_refptr<base::RefCountedMemory> ReadCursorFile(
     const std::string& rm_xcursor_theme) {
   constexpr const char kDefaultTheme[] = "default";
   std::string themes[] = {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // The toolkit theme has the highest priority.
     LinuxUi::instance() ? LinuxUi::instance()->GetCursorThemeName()
                         : std::string(),
@@ -443,7 +447,7 @@ uint32_t XCursorLoader::GetPreferredCursorSize() const
   if (base::StringToInt(GetEnv(kXcursorSizeEnv), &size) && size > 0)
     return size;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Let the toolkit have the next say.
   auto* linux_ui = LinuxUi::instance();
   size = linux_ui ? linux_ui->GetCursorThemeSize() : 0;
