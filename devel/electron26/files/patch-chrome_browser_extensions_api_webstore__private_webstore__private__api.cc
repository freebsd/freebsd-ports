--- chrome/browser/extensions/api/webstore_private/webstore_private_api.cc.orig	2023-08-10 01:48:35 UTC
+++ chrome/browser/extensions/api/webstore_private/webstore_private_api.cc
@@ -917,7 +917,7 @@ void WebstorePrivateBeginInstallWithManifest3Function:
         RequestExtensionApproval(contents);
         return;
       }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       // Shows a parental permission dialog directly bypassing the extension
       // install dialog view. The parental permission dialog contains a superset
       // of data from the extension install dialog: requested extension
