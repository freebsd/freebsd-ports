--- chrome/browser/profiles/profile_manager.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/profiles/profile_manager.cc
@@ -1500,7 +1500,7 @@ void ProfileManager::DoFinalInitForServices(Profile* p
   // Ensure PreloadingModelKeyedService is started.
   PreloadingModelKeyedServiceFactory::GetForProfile(profile);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   contextual_cueing::ContextualCueingServiceFactory::GetForProfile(profile);
 #endif
 
