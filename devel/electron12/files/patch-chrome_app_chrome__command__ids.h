--- chrome/app/chrome_command_ids.h.orig	2021-04-14 01:08:37 UTC
+++ chrome/app/chrome_command_ids.h
@@ -64,7 +64,7 @@
 #define IDC_NAME_WINDOW                 34049
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #define IDC_USE_SYSTEM_TITLE_BAR        34051
 #define IDC_RESTORE_WINDOW              34052
 #endif
