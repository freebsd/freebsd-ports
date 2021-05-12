--- printing/printing_features.cc.orig	2021-04-14 01:08:53 UTC
+++ printing/printing_features.cc
@@ -49,13 +49,13 @@ bool ShouldPrintUsingXps(bool source_is_pdf) {
 }
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 // Enables printing interactions with the operating system to be performed
 // out-of-process.
 const base::Feature kEnableOopPrintDrivers{"EnableOopPrintDrivers",
                                            base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 }  // namespace features
