--- chrome/renderer/chrome_content_renderer_client.cc.orig	2019-12-12 12:39:21 UTC
+++ chrome/renderer/chrome_content_renderer_client.cc
@@ -154,13 +154,13 @@
 #include "chrome/renderer/searchbox/searchbox_extension.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
 #if BUILDFLAG(USE_TCMALLOC)
 #include "chrome/common/performance_manager/mojom/tcmalloc.mojom.h"
 #include "chrome/renderer/performance_manager/mechanisms/tcmalloc_tunables_impl.h"
 #endif  // BUILDFLAG(USE_TCMALLOC)
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 #endif
@@ -1040,7 +1040,7 @@ WebPlugin* ChromeContentRendererClient::CreatePlugin(
       }
 
       case chrome::mojom::PluginStatus::kRestartRequired: {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         placeholder =
             create_blocked_plugin(IDR_BLOCKED_PLUGIN_HTML,
                                   l10n_util::GetStringFUTF16(
@@ -1636,7 +1636,7 @@ void ChromeContentRendererClient::BindReceiverOnMainTh
   }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #if BUILDFLAG(USE_TCMALLOC)
   if (auto setter_receiver = receiver.As<tcmalloc::mojom::TcmallocTunables>()) {
     performance_manager::mechanism::TcmallocTunablesImpl::Create(
@@ -1644,7 +1644,7 @@ void ChromeContentRendererClient::BindReceiverOnMainTh
     return;
   }
 #endif  // BUILDFLAG(USE_TCMALLOC)
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   // TODO(crbug.com/977637): Get rid of the use of BinderRegistry here. This was
   // done only to avoid churning spellcheck code while eliminting the "chrome"
