--- chrome/browser/chrome_browser_main_posix.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -72,7 +72,7 @@ void ExitHandler::ExitWhenPossibleOnUIThread(int signa
   } else {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     switch (signal) {
       case SIGINT:
       case SIGHUP:
