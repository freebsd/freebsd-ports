--- chrome/common/chrome_paths.h.orig	2022-06-17 14:20:10 UTC
+++ chrome/common/chrome_paths.h
@@ -56,7 +56,7 @@ enum {
 #if BUILDFLAG(IS_CHROMEOS_ASH) ||                              \
     ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
      BUILDFLAG(CHROMIUM_BRANDING)) ||                          \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   DIR_USER_EXTERNAL_EXTENSIONS,  // Directory for per-user external extensions
                                  // on Chrome Mac and Chromium Linux.
                                  // On Chrome OS, this path is used for OEM
@@ -64,7 +64,7 @@ enum {
                                  // create it.
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   DIR_STANDALONE_EXTERNAL_EXTENSIONS,  // Directory for 'per-extension'
                                        // definition manifest files that
                                        // describe extensions which are to be
@@ -117,7 +117,7 @@ enum {
   DIR_CHROMEOS_CUSTOM_WALLPAPERS,     // Directory where custom wallpapers
                                       // reside.
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   DIR_NATIVE_MESSAGING,       // System directory where native messaging host
                               // manifest files are stored.
   DIR_USER_NATIVE_MESSAGING,  // Directory with Native Messaging Hosts
