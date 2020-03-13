--- chrome/browser/plugins/plugin_info_host_impl.cc.orig	2019-12-12 12:39:11 UTC
+++ chrome/browser/plugins/plugin_info_host_impl.cc
@@ -383,7 +383,7 @@ void PluginInfoHostImpl::ComponentPluginLookupDone(
     std::unique_ptr<component_updater::ComponentInfo> cus_plugin_info) {
   if (cus_plugin_info) {
     output->status = chrome::mojom::PluginStatus::kComponentUpdateRequired;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     if (cus_plugin_info->version != base::Version("0")) {
       output->status = chrome::mojom::PluginStatus::kRestartRequired;
     }
