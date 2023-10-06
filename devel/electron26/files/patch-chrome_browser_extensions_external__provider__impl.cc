--- chrome/browser/extensions/external_provider_impl.cc.orig	2023-08-10 01:48:35 UTC
+++ chrome/browser/extensions/external_provider_impl.cc
@@ -829,7 +829,7 @@ void ExternalProviderImpl::CreateExternalProviders(
   if (!profile->GetPrefs()->GetBoolean(pref_names::kBlockExternalExtensions)) {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
         base::MakeRefCounted<ExternalPrefLoader>(
@@ -857,7 +857,7 @@ void ExternalProviderImpl::CreateExternalProviders(
         bundled_extension_creation_flags));
 
     // Define a per-user source of external extensions.
-#if BUILDFLAG(IS_MAC) || ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if BUILDFLAG(IS_MAC) || ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
                           BUILDFLAG(CHROMIUM_BRANDING))
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
