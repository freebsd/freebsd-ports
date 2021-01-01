--- third_party/pdfium/xfa/fgas/font/cfx_fontsourceenum_file.cpp.orig	2019-12-12 12:45:42 UTC
+++ third_party/pdfium/xfa/fgas/font/cfx_fontsourceenum_file.cpp
@@ -16,9 +16,8 @@ constexpr char kFolderSeparator = '/';
 
 constexpr const char* kFontFolders[] = {
 #if _FX_PLATFORM_ == _FX_PLATFORM_LINUX_
-    "/usr/share/fonts",
-    "/usr/share/X11/fonts/Type1",
-    "/usr/share/X11/fonts/TTF",
+    "/usr/local/share/fonts/Type1",
+    "/usr/local/share/fonts/TTF",
     "/usr/local/share/fonts",
 #elif defined(OS_MACOSX)
     "~/Library/Fonts",
