--- chrome/browser/browser_process_impl.h.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/browser_process_impl.h
@@ -404,7 +404,7 @@ class BrowserProcessImpl : public BrowserProcess,
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
   base::RepeatingTimer autoupdate_timer_;
 
   // Gets called by autoupdate timer to see if browser needs restart and can be
