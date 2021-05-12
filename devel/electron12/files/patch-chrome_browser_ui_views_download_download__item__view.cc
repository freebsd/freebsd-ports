--- chrome/browser/ui/views/download/download_item_view.cc.orig	2021-04-14 01:08:41 UTC
+++ chrome/browser/ui/views/download/download_item_view.cc
@@ -189,7 +189,7 @@ bool UseNewWarnings() {
 }
 
 int GetFilenameStyle(const views::Label& label) {
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
   if (UseNewWarnings())
     return STYLE_EMPHASIZED;
 #endif
@@ -197,7 +197,7 @@ int GetFilenameStyle(const views::Label& label) {
 }
 
 int GetFilenameStyle(const views::StyledLabel& label) {
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
   if (UseNewWarnings())
     return STYLE_EMPHASIZED;
 #endif
