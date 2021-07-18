--- chrome/common/chrome_paths.h.orig	2021-04-14 01:08:42 UTC
+++ chrome/common/chrome_paths.h
@@ -53,9 +53,9 @@ enum {
 #endif
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_CHROMEOS) ||                                  \
-    ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
-     BUILDFLAG(CHROMIUM_BRANDING)) ||                        \
+#if defined(OS_CHROMEOS) ||                                                     \
+    ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) && \
+     BUILDFLAG(CHROMIUM_BRANDING)) ||                                           \
     defined(OS_MAC)
   DIR_USER_EXTERNAL_EXTENSIONS,  // Directory for per-user external extensions
                                  // on Chrome Mac and Chromium Linux.
@@ -64,7 +64,7 @@ enum {
                                  // create it.
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   DIR_STANDALONE_EXTERNAL_EXTENSIONS,  // Directory for 'per-extension'
                                        // definition manifest files that
                                        // describe extensions which are to be
@@ -118,7 +118,7 @@ enum {
   DIR_CHROMEOS_CUSTOM_WALLPAPERS,     // Directory where custom wallpapers
                                       // reside.
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   DIR_NATIVE_MESSAGING,       // System directory where native messaging host
                               // manifest files are stored.
   DIR_USER_NATIVE_MESSAGING,  // Directory with Native Messaging Hosts
