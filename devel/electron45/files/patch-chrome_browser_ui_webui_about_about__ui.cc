--- chrome/browser/ui/webui/about/about_ui.cc.orig	2026-10-19 21:50:55 UTC
+++ chrome/browser/ui/webui/about/about_ui.cc
@@ -406,7 +406,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data,
@@ -436,7 +436,7 @@ TermsUIConfig::TermsUIConfig()
     : AboutUIConfigBase(chrome::kChromeUITermsHost) {}
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 LinuxProxyConfigUI::LinuxProxyConfigUI()
     : AboutUIConfigBase(chrome::kChromeUILinuxProxyConfigHost) {}
 #endif
@@ -482,7 +482,7 @@ void AboutUIHTMLSource::StartDataRequest(
       response =
           ui::ResourceBundle::GetSharedInstance().LoadDataResourceString(idr);
     }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
