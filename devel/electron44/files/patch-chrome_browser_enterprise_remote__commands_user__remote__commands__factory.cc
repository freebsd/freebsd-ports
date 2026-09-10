--- chrome/browser/enterprise/remote_commands/user_remote_commands_factory.cc.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/enterprise/remote_commands/user_remote_commands_factory.cc
@@ -22,7 +22,7 @@ UserRemoteCommandsFactory::BuildJobForType(
   switch (type) {
     case enterprise_management::RemoteCommand_Type_BROWSER_CLEAR_BROWSING_DATA:
       return std::make_unique<ClearBrowsingDataJob>(profile_);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case enterprise_management::
         RemoteCommand_Type_BROWSER_EXTENSION_UPDATE_CHECK:
       return std::make_unique<ExtensionUpdateCheckJob>(profile_);
