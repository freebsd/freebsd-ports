--- content/public/common/content_features.cc.orig	2019-04-08 08:32:55 UTC
+++ content/public/common/content_features.cc
@@ -493,7 +493,7 @@ const base::Feature kWebAssemblyThreads{"WebAssemblyTh
                                         base::FEATURE_DISABLED_BY_DEFAULT};
 
 // Enable WebAssembly trap handler.
-#if defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(ARCH_CPU_X86_64)
 const base::Feature kWebAssemblyTrapHandler{"WebAssemblyTrapHandler",
                                             base::FEATURE_ENABLED_BY_DEFAULT};
 #else
