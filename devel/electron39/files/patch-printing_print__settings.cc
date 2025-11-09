--- printing/print_settings.cc.orig	2025-06-30 07:04:30 UTC
+++ printing/print_settings.cc
@@ -319,7 +319,7 @@ PrintSettings& PrintSettings::operator=(const PrintSet
 #endif
   is_modifiable_ = settings.is_modifiable_;
   pages_per_sheet_ = settings.pages_per_sheet_;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   for (const auto& item : settings.advanced_settings_)
     advanced_settings_.emplace(item.first, item.second.Clone());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -349,7 +349,7 @@ bool PrintSettings::operator==(const PrintSettings& ot
 #endif
                   is_modifiable_, requested_custom_margins_in_microns_,
                   pages_per_sheet_
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                   ,
                   advanced_settings_
 #endif
@@ -373,7 +373,7 @@ bool PrintSettings::operator==(const PrintSettings& ot
                   other.is_modifiable_,
                   other.requested_custom_margins_in_microns_,
                   other.pages_per_sheet_
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                   ,
                   other.advanced_settings_
 #endif
@@ -413,7 +413,7 @@ void PrintSettings::Clear() {
 #endif
   is_modifiable_ = true;
   pages_per_sheet_ = 1;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   advanced_settings_.clear();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_CHROMEOS)
