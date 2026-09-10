--- chrome/browser/feedback/show_feedback_page.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/feedback/show_feedback_page.cc
@@ -256,7 +256,7 @@ bool CanShowFeedback(const Profile* profile) {
     return false;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(switches::kDisableU18FeedbackDesktop)) {
     return true;
   }
