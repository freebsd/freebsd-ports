--- chrome/test/chromedriver/chrome/chrome_finder.cc.orig	2022-05-19 05:17:39 UTC
+++ chrome/test/chromedriver/chrome/chrome_finder.cc
@@ -54,7 +54,7 @@ void GetApplicationDirs(std::vector<base::FilePath>* l
         installation_locations[i].Append(L"Chromium\\Application"));
   }
 }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void GetApplicationDirs(std::vector<base::FilePath>* locations) {
   // TODO: Respect users' PATH variables.
   // Until then, we use an approximation of the most common defaults.
@@ -139,7 +139,7 @@ bool FindChrome(base::FilePath* browser_exe) {
   base::FilePath browser_exes_array[] = {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
     base::FilePath(chrome::kBrowserProcessExecutablePath),
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     base::FilePath("google-chrome"),
     base::FilePath(chrome::kBrowserProcessExecutablePath),
     base::FilePath("chromium"),
