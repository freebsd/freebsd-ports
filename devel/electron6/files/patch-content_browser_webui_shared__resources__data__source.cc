--- content/browser/webui/shared_resources_data_source.cc.orig	2019-09-10 11:14:02 UTC
+++ content/browser/webui/shared_resources_data_source.cc
@@ -119,12 +119,12 @@ const std::map<int, std::string> CreateMojoResourceIdT
          "mojo/mojo/public/mojom/base/string16.mojom.html"},
         {IDR_MOJO_STRING16_MOJOM_LITE_JS,
          "mojo/mojo/public/mojom/base/string16.mojom-lite.js"},
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
         {IDR_MOJO_TIME_MOJOM_HTML,
          "mojo/mojo/public/mojom/base/time.mojom.html"},
         {IDR_MOJO_TIME_MOJOM_LITE_JS,
          "mojo/mojo/public/mojom/base/time.mojom-lite.js"},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   };
 }
 
