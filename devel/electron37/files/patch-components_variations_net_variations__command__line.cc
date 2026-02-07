--- components/variations/net/variations_command_line.cc.orig	2025-06-30 07:04:30 UTC
+++ components/variations/net/variations_command_line.cc
@@ -50,7 +50,7 @@ namespace variations {
 namespace variations {
 
 #if !BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kFeedbackIncludeVariations,
              "FeedbackIncludeVariations",
              base::FEATURE_ENABLED_BY_DEFAULT);
