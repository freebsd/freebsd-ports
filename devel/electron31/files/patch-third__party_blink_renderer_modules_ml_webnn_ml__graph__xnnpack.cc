--- third_party/blink/renderer/modules/ml/webnn/ml_graph_xnnpack.cc.orig	2024-04-15 20:34:06 UTC
+++ third_party/blink/renderer/modules/ml/webnn/ml_graph_xnnpack.cc
@@ -204,7 +204,7 @@ class SharedXnnpackContext : public ThreadSafeRefCount
 
   ~SharedXnnpackContext() {
     base::AutoLock auto_lock(SharedXnnpackContextLock());
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
     // For Linux and ChromeOS, cpuinfo needs to parse /proc/cpuinfo to
     // initialize in pre sandbox stage. Calling xnn_deinitialize() here will
     // deinitialize cpuinfo within sandbox and cannot access /proc/cpuinfo
