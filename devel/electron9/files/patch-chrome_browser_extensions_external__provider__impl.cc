--- chrome/browser/extensions/external_provider_impl.cc.orig	2020-05-26 08:03:18 UTC
+++ chrome/browser/extensions/external_provider_impl.cc
@@ -760,7 +760,7 @@ void ExternalProviderImpl::CreateExternalProviders(
   }
 #endif
   if (!profile->GetPrefs()->GetBoolean(pref_names::kBlockExternalExtensions)) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
         base::MakeRefCounted<ExternalPrefLoader>(
@@ -787,7 +787,7 @@ void ExternalProviderImpl::CreateExternalProviders(
           bundled_extension_creation_flags));
 
       // Define a per-user source of external extensions.
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && BUILDFLAG(CHROMIUM_BRANDING))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(CHROMIUM_BRANDING))
       provider_list->push_back(std::make_unique<ExternalProviderImpl>(
           service,
           base::MakeRefCounted<ExternalPrefLoader>(
