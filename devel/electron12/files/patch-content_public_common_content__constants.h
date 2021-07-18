--- content/public/common/content_constants.h.orig	2021-04-14 01:08:48 UTC
+++ content/public/common/content_constants.h
@@ -64,7 +64,7 @@ CONTENT_EXPORT extern const char kCorsExemptPurposeHea
 // it at run time.
 CONTENT_EXPORT std::string GetCorsExemptRequestedWithHeaderName();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // The OOM score adj constants
 // The highest and lowest assigned OOM score adjustment (oom_score_adj) for
 // renderers and extensions used by the OomPriority Manager.
