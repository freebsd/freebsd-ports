--- chrome/browser/ui/startup/startup_browser_creator_impl.cc.orig	2022-10-24 13:33:33 UTC
+++ chrome/browser/ui/startup/startup_browser_creator_impl.cc
@@ -257,7 +257,7 @@ Browser* StartupBrowserCreatorImpl::OpenTabsInBrowser(
     // at the state of the MessageLoop.
     Browser::CreateParams params = Browser::CreateParams(profile_, false);
     params.creation_source = Browser::CreationSource::kStartupCreator;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.startup_id = command_line_.GetSwitchValueASCII("desktop-startup-id");
 #endif
     browser = Browser::Create(params);
