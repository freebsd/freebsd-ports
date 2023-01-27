--- chrome/browser/chrome_browser_main_posix.cc.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -73,7 +73,7 @@ void ExitHandler::ExitWhenPossibleOnUIThread(int signa
   } else {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     switch (signal) {
       case SIGINT:
       case SIGHUP:
