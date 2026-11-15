--- chrome/browser/feedback/show_feedback_page.h.orig	2026-10-19 21:50:55 UTC
+++ chrome/browser/feedback/show_feedback_page.h
@@ -17,7 +17,7 @@ namespace chrome {
 
 namespace chrome {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // These values are persisted to logs. Entries should not be renumbered and
 // numeric values should never be reused.
 //
