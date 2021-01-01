--- chrome/browser/plugins/plugin_info_host_impl.cc.orig	2019-09-10 11:13:41 UTC
+++ chrome/browser/plugins/plugin_info_host_impl.cc
@@ -411,7 +411,7 @@ void PluginInfoHostImpl::ComponentPluginLookupDone(
     std::unique_ptr<component_updater::ComponentInfo> cus_plugin_info) {
   if (cus_plugin_info) {
     output->status = chrome::mojom::PluginStatus::kComponentUpdateRequired;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     if (cus_plugin_info->version != base::Version("0")) {
       output->status = chrome::mojom::PluginStatus::kRestartRequired;
     }
