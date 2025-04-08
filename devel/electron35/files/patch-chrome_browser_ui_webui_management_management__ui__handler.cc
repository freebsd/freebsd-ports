--- chrome/browser/ui/webui/management/management_ui_handler.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/ui/webui/management/management_ui_handler.cc
@@ -58,7 +58,7 @@
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/webui/web_ui_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/user_permission_service_factory.h"
 #include "components/device_signals/core/browser/user_permission_service.h"  // nogncheck
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -359,7 +359,7 @@ void ManagementUIHandler::AddReportingInfo(base::Value
       report_sources->Append(std::move(data));
     }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auto device_signal_data = GetDeviceSignalGrantedMessage();
     if (!device_signal_data.empty()) {
       report_sources->Append(std::move(device_signal_data));
@@ -381,7 +381,7 @@ void ManagementUIHandler::AddReportingInfo(base::Value
       report_sources->Append(std::move(data));
     }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auto device_signal_data = GetDeviceSignalGrantedMessage();
     if (!device_signal_data.empty()) {
       report_sources->Append(std::move(device_signal_data));
@@ -567,7 +567,7 @@ policy::PolicyService* ManagementUIHandler::GetPolicyS
       ->policy_service();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 device_signals::UserPermissionService*
 ManagementUIHandler::GetUserPermissionService() {
   return enterprise_signals::UserPermissionServiceFactory::GetForProfile(
