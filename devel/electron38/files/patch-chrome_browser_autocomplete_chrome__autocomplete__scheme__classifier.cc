--- chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc
@@ -104,7 +104,7 @@ ChromeAutocompleteSchemeClassifier::GetInputTypeForSch
       return metrics::OmniboxInputType::QUERY;
 
     case ExternalProtocolHandler::UNKNOWN: {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Linux impl of GetApplicationNameForScheme doesn't distinguish
       // between URL schemes with handers and those without. This will
       // make the default behaviour be search on Linux.
