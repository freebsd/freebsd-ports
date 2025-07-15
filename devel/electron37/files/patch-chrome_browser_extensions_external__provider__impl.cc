--- chrome/browser/extensions/external_provider_impl.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/extensions/external_provider_impl.cc
@@ -828,7 +828,7 @@ void ExternalProviderImpl::CreateExternalProviders(
 
 #endif  // BUILDFLAG(IS_CHROMEOS)
   if (!profile->GetPrefs()->GetBoolean(pref_names::kBlockExternalExtensions)) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
         base::MakeRefCounted<ExternalPrefLoader>(
@@ -856,7 +856,7 @@ void ExternalProviderImpl::CreateExternalProviders(
         bundled_extension_creation_flags));
 
     // Define a per-user source of external extensions.
-#if BUILDFLAG(IS_MAC) || ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if BUILDFLAG(IS_MAC) || ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
                           BUILDFLAG(CHROMIUM_BRANDING))
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
