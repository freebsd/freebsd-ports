--- base/memory/discardable_memory.cc.orig	2022-05-19 14:06:27 UTC
+++ base/memory/discardable_memory.cc
@@ -25,7 +25,7 @@ const base::Feature kMadvFreeDiscardableMemory{
     "MadvFreeDiscardableMemory", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const base::Feature kDiscardableMemoryBackingTrial{
     "DiscardableMemoryBackingTrial", base::FEATURE_DISABLED_BY_DEFAULT};
 
@@ -50,7 +50,7 @@ const base::FeatureParam<DiscardableMemoryTrialGroup>
 
 namespace {
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 DiscardableMemoryBacking GetBackingForFieldTrial() {
   DiscardableMemoryTrialGroup trial_group =
@@ -69,7 +69,7 @@ DiscardableMemoryBacking GetBackingForFieldTrial() {
 
 }  // namespace
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 // Probe capabilities of this device to determine whether we should participate
 // in the discardable memory backing trial.
@@ -99,7 +99,7 @@ DiscardableMemory::DiscardableMemory() = default;
 DiscardableMemory::~DiscardableMemory() = default;
 
 DiscardableMemoryBacking GetDiscardableMemoryBacking() {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (DiscardableMemoryBackingFieldTrialIsEnabled()) {
     return GetBackingForFieldTrial();
   }
