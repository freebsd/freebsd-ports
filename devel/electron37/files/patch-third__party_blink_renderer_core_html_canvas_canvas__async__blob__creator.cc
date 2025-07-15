--- third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc.orig	2025-04-22 20:15:27 UTC
+++ third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc
@@ -51,7 +51,7 @@ constexpr base::TimeDelta kEncodeRowSlackBeforeDeadlin
 
 /* The value is based on user statistics on Nov 2017. */
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-     BUILDFLAG(IS_WIN))
+     BUILDFLAG(IS_WIN)) || BUILDFLAG(IS_BSD)
 const double kIdleTaskStartTimeoutDelayMs = 1000.0;
 #else
 const double kIdleTaskStartTimeoutDelayMs = 4000.0;  // For ChromeOS, Mobile
