--- printing/mojom/printing_context_mojom_traits.h.orig	2023-10-19 19:58:29 UTC
+++ printing/mojom/printing_context_mojom_traits.h
@@ -166,7 +166,7 @@ struct StructTraits<printing::mojom::PrintSettingsData
     return s.pages_per_sheet();
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static const printing::PrintSettings::AdvancedSettings& advanced_settings(
       const printing::PrintSettings& s) {
     return s.advanced_settings();
