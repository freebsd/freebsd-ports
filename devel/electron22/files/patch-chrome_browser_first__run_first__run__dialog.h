--- chrome/browser/first_run/first_run_dialog.h.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/first_run/first_run_dialog.h
@@ -12,7 +12,7 @@
 // Hide this function on platforms where the dialog does not exist.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
 
 namespace first_run {
 
