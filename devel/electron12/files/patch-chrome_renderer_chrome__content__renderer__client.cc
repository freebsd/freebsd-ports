--- chrome/renderer/chrome_content_renderer_client.cc.orig	2021-04-22 07:51:50 UTC
+++ chrome/renderer/chrome_content_renderer_client.cc
@@ -1097,7 +1097,7 @@ WebPlugin* ChromeContentRendererClient::CreatePlugin(
       }
 
       case chrome::mojom::PluginStatus::kRestartRequired: {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
         placeholder =
             create_blocked_plugin(IDR_BLOCKED_PLUGIN_HTML,
                                   l10n_util::GetStringFUTF16(
