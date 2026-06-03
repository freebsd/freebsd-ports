--- chrome/test/chromedriver/chrome/chrome_finder.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/test/chromedriver/chrome/chrome_finder.cc
@@ -59,7 +59,7 @@ void GetApplicationDirs(std::vector<base::FilePath>* l
         installation_locations[i].Append(L"Chromium\\Application"));
   }
 }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void GetApplicationDirs(std::vector<base::FilePath>* locations) {
   // TODO: Respect users' PATH variables.
   // Until then, we use an approximation of the most common defaults.
@@ -126,7 +126,7 @@ std::vector<base::FilePath> GetChromeProgramNames() {
             chrome::kGoogleChromeForTestingBrowserProcessExecutablePath),
         base::FilePath(chrome::kGoogleChromeBrowserProcessExecutablePath),
         base::FilePath(chrome::kChromiumBrowserProcessExecutablePath),
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     base::FilePath(chrome::kBrowserProcessExecutablePath),
         base::FilePath("chrome"),  // Chrome for Testing or Google Chrome
         base::FilePath("google-chrome"), base::FilePath("chromium"),
@@ -142,7 +142,7 @@ std::vector<base::FilePath> GetHeadlessShellProgramNam
   return {
 #if BUILDFLAG(IS_WIN)
     base::FilePath(FILE_PATH_LITERAL("chrome-headless-shell.exe")),
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     base::FilePath("chrome-headless-shell"),
 #else
     // it will compile but won't work on other OSes
