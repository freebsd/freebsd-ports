--- printing/print_settings_conversion.cc.orig	2024-04-15 20:34:03 UTC
+++ printing/print_settings_conversion.cc
@@ -285,7 +285,7 @@ std::unique_ptr<PrintSettings> PrintSettingsFromJobSet
     settings->set_is_modifiable(is_modifiable.value());
   }
 
-#if BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_CUPS))
+#if BUILDFLAG(IS_CHROMEOS) || ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_CUPS))
   const base::Value::Dict* advanced_settings =
       job_settings.FindDict(kSettingAdvancedSettings);
   if (advanced_settings) {
