--- chrome/test/chromedriver/chrome/chrome_finder.cc.orig	2023-08-10 01:48:37 UTC
+++ chrome/test/chromedriver/chrome/chrome_finder.cc
@@ -57,7 +57,7 @@ void GetApplicationDirs(std::vector<base::FilePath>* l
         installation_locations[i].Append(L"Chromium\\Application"));
   }
 }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void GetApplicationDirs(std::vector<base::FilePath>* locations) {
   // TODO: Respect users' PATH variables.
   // Until then, we use an approximation of the most common defaults.
@@ -157,7 +157,7 @@ bool FindChrome(base::FilePath* browser_exe) {
     base::FilePath(chrome::kGoogleChromeForTestingBrowserProcessExecutablePath),
     base::FilePath(chrome::kGoogleChromeBrowserProcessExecutablePath),
     base::FilePath(chrome::kChromiumBrowserProcessExecutablePath),
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     base::FilePath(chrome::kBrowserProcessExecutablePath),
     base::FilePath("chrome"),  // Chrome for Testing or Google Chrome
     base::FilePath("google-chrome"),
