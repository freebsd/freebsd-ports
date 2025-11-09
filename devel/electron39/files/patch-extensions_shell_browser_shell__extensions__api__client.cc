--- extensions/shell/browser/shell_extensions_api_client.cc.orig	2025-06-30 07:04:30 UTC
+++ extensions/shell/browser/shell_extensions_api_client.cc
@@ -18,7 +18,7 @@
 #include "extensions/shell/browser/shell_extension_web_contents_observer.h"
 #include "extensions/shell/browser/shell_virtual_keyboard_delegate.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "extensions/shell/browser/api/file_system/shell_file_system_delegate.h"
 #endif
 
@@ -76,7 +76,7 @@ ShellExtensionsAPIClient::CreateDisplayInfoProvider() 
   return std::make_unique<ShellDisplayInfoProvider>();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 FileSystemDelegate* ShellExtensionsAPIClient::GetFileSystemDelegate() {
   if (!file_system_delegate_)
     file_system_delegate_ = std::make_unique<ShellFileSystemDelegate>();
