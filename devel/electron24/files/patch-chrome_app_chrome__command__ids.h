--- chrome/app/chrome_command_ids.h.orig	2023-03-30 00:33:39 UTC
+++ chrome/app/chrome_command_ids.h
@@ -70,7 +70,7 @@
 #endif
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #define IDC_USE_SYSTEM_TITLE_BAR        34051
 #define IDC_RESTORE_WINDOW              34052
 #endif
