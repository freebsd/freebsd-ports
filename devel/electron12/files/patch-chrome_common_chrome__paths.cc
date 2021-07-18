--- chrome/common/chrome_paths.cc.orig	2021-04-14 01:08:42 UTC
+++ chrome/common/chrome_paths.cc
@@ -48,21 +48,29 @@ namespace {
 const base::FilePath::CharType kPepperFlashBaseDirectory[] =
     FILE_PATH_LITERAL("PepperFlash");
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // The path to the external extension <id>.json files.
 // /usr/share seems like a good choice, see: http://www.pathname.com/fhs/
 const base::FilePath::CharType kFilepathSinglePrefExtensions[] =
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
+#if defined(OS_BSD)
+    FILE_PATH_LITERAL("/usr/local/share/google-chrome/extensions");
+#else
     FILE_PATH_LITERAL("/usr/share/google-chrome/extensions");
+#endif
 #else
+#if defined(OS_BSD)
+    FILE_PATH_LITERAL("/usr/local/share/chromium/extensions");
+#else
     FILE_PATH_LITERAL("/usr/share/chromium/extensions");
+#endif
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 
 // The path to the hint file that tells the pepper plugin loader
 // where it can find the latest component updated flash.
 const base::FilePath::CharType kComponentUpdatedFlashHint[] =
     FILE_PATH_LITERAL("latest-component-updated-flash");
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && \
     BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT)
@@ -183,7 +191,7 @@ bool PathProvider(int key, base::FilePath* result) {
         return false;
       break;
     case chrome::DIR_DEFAULT_DOWNLOADS_SAFE:
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       if (!GetUserDownloadsDirectorySafe(&cur))
         return false;
       break;
@@ -447,6 +455,9 @@ bool PathProvider(int key, base::FilePath* result) {
     case chrome::DIR_POLICY_FILES: {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
       cur = base::FilePath(FILE_PATH_LITERAL("/etc/opt/chrome/policies"));
+#elif defined(OS_BSD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/chrome/policies"));
 #else
       cur = base::FilePath(FILE_PATH_LITERAL("/etc/chromium/policies"));
 #endif
@@ -455,9 +466,9 @@ bool PathProvider(int key, base::FilePath* result) {
 #endif
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_CHROMEOS) ||                                  \
-    ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
-     BUILDFLAG(CHROMIUM_BRANDING)) ||                        \
+#if defined(OS_CHROMEOS) ||                                                    \
+    ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) && \
+     BUILDFLAG(CHROMIUM_BRANDING)) ||                                           \
     defined(OS_MAC)
     case chrome::DIR_USER_EXTERNAL_EXTENSIONS: {
       if (!base::PathService::Get(chrome::DIR_USER_DATA, &cur))
@@ -466,7 +477,7 @@ bool PathProvider(int key, base::FilePath* result) {
       break;
     }
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     case chrome::DIR_STANDALONE_EXTERNAL_EXTENSIONS: {
       cur = base::FilePath(kFilepathSinglePrefExtensions);
       break;
@@ -501,7 +512,7 @@ bool PathProvider(int key, base::FilePath* result) {
 #endif
       break;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
     case chrome::DIR_NATIVE_MESSAGING:
 #if defined(OS_MAC)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
@@ -515,6 +526,9 @@ bool PathProvider(int key, base::FilePath* result) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/opt/chrome/native-messaging-hosts"));
+#elif defined(OS_BSD)
+      cur = base::FilePath(FILE_PATH_LITERAL(
+          "/usr/local/etc/chrome/native-messaging-hosts"));
 #else
       cur = base::FilePath(FILE_PATH_LITERAL(
           "/etc/chromium/native-messaging-hosts"));
@@ -527,7 +541,7 @@ bool PathProvider(int key, base::FilePath* result) {
         return false;
       cur = cur.Append(FILE_PATH_LITERAL("NativeMessagingHosts"));
       break;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
 #if !defined(OS_ANDROID)
     case chrome::DIR_GLOBAL_GCM_STORE:
       if (!base::PathService::Get(chrome::DIR_USER_DATA, &cur))
