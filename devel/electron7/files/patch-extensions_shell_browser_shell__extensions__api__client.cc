--- extensions/shell/browser/shell_extensions_api_client.cc.orig	2019-12-12 12:39:44 UTC
+++ extensions/shell/browser/shell_extensions_api_client.cc
@@ -16,7 +16,7 @@
 #include "extensions/shell/browser/shell_virtual_keyboard_delegate.h"
 #include "extensions/shell/browser/shell_web_view_guest_delegate.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "extensions/shell/browser/api/file_system/shell_file_system_delegate.h"
 #endif
 
@@ -52,7 +52,7 @@ ShellExtensionsAPIClient::CreateDisplayInfoProvider() 
   return std::make_unique<ShellDisplayInfoProvider>();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 FileSystemDelegate* ShellExtensionsAPIClient::GetFileSystemDelegate() {
   if (!file_system_delegate_)
     file_system_delegate_ = std::make_unique<ShellFileSystemDelegate>();
