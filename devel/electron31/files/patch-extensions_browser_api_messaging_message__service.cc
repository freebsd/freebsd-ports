--- extensions/browser/api/messaging/message_service.cc.orig	2024-04-15 20:33:59 UTC
+++ extensions/browser/api/messaging/message_service.cc
@@ -71,7 +71,7 @@ const char kReceivingEndDoesntExistError[] =
 const char kReceivingEndDoesntExistError[] =
     "Could not establish connection. Receiving end does not exist.";
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kMissingPermissionError[] =
     "Access to native messaging requires nativeMessaging permission.";
 const char kProhibitedByPoliciesError[] =
@@ -541,7 +541,7 @@ void MessageService::OpenChannelToNativeAppImpl(
     return;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool has_permission = extension->permissions_data()->HasAPIPermission(
       mojom::APIPermissionID::kNativeMessaging);
   if (!has_permission) {
