--- printing/print_settings_conversion.cc.orig	2022-05-19 05:17:45 UTC
+++ printing/print_settings_conversion.cc
@@ -217,7 +217,7 @@ std::unique_ptr<PrintSettings> PrintSettingsFromJobSet
     settings->set_is_modifiable(is_modifiable.value());
   }
 
-#if BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && defined(USE_CUPS))
+#if BUILDFLAG(IS_CHROMEOS) || ((BUILDFLAG(IS_BSD) || BUILDFLAG(IS_LINUX)) && defined(USE_CUPS))
   const base::Value* advanced_settings =
       job_settings.FindDictKey(kSettingAdvancedSettings);
   if (advanced_settings) {
