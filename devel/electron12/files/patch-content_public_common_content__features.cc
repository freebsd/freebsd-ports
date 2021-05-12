--- content/public/common/content_features.cc.orig	2021-04-14 01:08:48 UTC
+++ content/public/common/content_features.cc
@@ -45,7 +45,7 @@ const base::Feature kAudioServiceOutOfProcess {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -773,8 +773,8 @@ const base::Feature kWebAssemblyThreads {
 };
 
 // Enable WebAssembly trap handler.
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
-     defined(OS_MAC)) &&                                             \
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD) || \
+     defined(OS_MAC)) &&                                                                \
     defined(ARCH_CPU_X86_64)
 const base::Feature kWebAssemblyTrapHandler{"WebAssemblyTrapHandler",
                                             base::FEATURE_ENABLED_BY_DEFAULT};
@@ -795,7 +795,7 @@ const base::Feature kWebAuthCable {
   "WebAuthenticationCable",
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
