--- components/supervised_user/core/browser/kids_chrome_management_url_checker_client.cc.orig	2026-03-13 16:54:03 UTC
+++ components/supervised_user/core/browser/kids_chrome_management_url_checker_client.cc
@@ -65,7 +65,7 @@ FetcherConfig GetFetcherConfig(
 
 FetcherConfig GetFetcherConfig(
     bool is_subject_to_family_link_parental_controls) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Supervised users on these platforms might get into a state where their
   // credentials are not available, so best-effort access mode is a graceful
   // fallback here.
