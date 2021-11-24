--- base/memory/discardable_memory.cc.orig	2021-07-15 19:13:29 UTC
+++ base/memory/discardable_memory.cc
@@ -24,7 +24,7 @@ const base::Feature kMadvFreeDiscardableMemory{
     "MadvFreeDiscardableMemory", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const base::Feature kDiscardableMemoryBackingTrial{
     "DiscardableMemoryBackingTrial", base::FEATURE_DISABLED_BY_DEFAULT};
 
@@ -42,13 +42,13 @@ const base::FeatureParam<DiscardableMemoryTrialGroup>
         DiscardableMemoryTrialGroup::kEmulatedSharedMemory,
         &kDiscardableMemoryBackingParamOptions};
 
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 }  // namespace features
 
 namespace {
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 DiscardableMemoryBacking GetBackingForFieldTrial() {
   DiscardableMemoryTrialGroup trial_group =
@@ -62,11 +62,11 @@ DiscardableMemoryBacking GetBackingForFieldTrial() {
   }
   NOTREACHED();
 }
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 }  // namespace
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // Probe capabilities of this device to determine whether we should participate
 // in the discardable memory backing trial.
@@ -88,18 +88,18 @@ DiscardableMemoryTrialGroup GetDiscardableMemoryBackin
   DCHECK(DiscardableMemoryBackingFieldTrialIsEnabled());
   return features::kDiscardableMemoryBackingParam.Get();
 }
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 DiscardableMemory::DiscardableMemory() = default;
 
 DiscardableMemory::~DiscardableMemory() = default;
 
 DiscardableMemoryBacking GetDiscardableMemoryBacking() {
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (DiscardableMemoryBackingFieldTrialIsEnabled()) {
     return GetBackingForFieldTrial();
   }
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
   if (ashmem_device_is_supported())
