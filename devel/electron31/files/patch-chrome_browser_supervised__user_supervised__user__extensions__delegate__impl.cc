--- chrome/browser/supervised_user/supervised_user_extensions_delegate_impl.cc.orig	2024-06-18 21:43:24 UTC
+++ chrome/browser/supervised_user/supervised_user_extensions_delegate_impl.cc
@@ -185,7 +185,7 @@ void SupervisedUserExtensionsDelegateImpl::RequestExte
       return;
     }
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   CHECK(contents.value());
   content::WebContents* web_contents = contents.value().get();
   if (CanInstallExtensions()) {
