--- chrome/common/chrome_paths.h.orig	2019-09-10 11:13:45 UTC
+++ chrome/common/chrome_paths.h
@@ -51,7 +51,7 @@ enum {
                                 // to set policies for chrome. This directory
                                 // contains subdirectories.
 #endif
-#if defined(OS_CHROMEOS) || (defined(OS_LINUX) && defined(CHROMIUM_BUILD)) || \
+#if defined(OS_CHROMEOS) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(CHROMIUM_BUILD)) || \
     defined(OS_MACOSX)
   DIR_USER_EXTERNAL_EXTENSIONS,  // Directory for per-user external extensions
                                  // on Chrome Mac and Chromium Linux.
@@ -60,7 +60,7 @@ enum {
                                  // create it.
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   DIR_STANDALONE_EXTERNAL_EXTENSIONS,  // Directory for 'per-extension'
                                        // definition manifest files that
                                        // describe extensions which are to be
@@ -107,7 +107,7 @@ enum {
   DIR_SUPERVISED_USER_INSTALLED_WHITELISTS,  // Directory where sanitized
                                              // supervised user whitelists are
                                              // installed.
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_MACOSX)
   DIR_NATIVE_MESSAGING,         // System directory where native messaging host
                                 // manifest files are stored.
   DIR_USER_NATIVE_MESSAGING,    // Directory with Native Messaging Hosts
@@ -122,10 +122,10 @@ enum {
   DIR_GEN_TEST_DATA,            // Directory where generated test data resides.
   DIR_TEST_DATA,                // Directory where unit test data resides.
   DIR_TEST_TOOLS,               // Directory where unit test tools reside.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   FILE_COMPONENT_FLASH_HINT,    // A file in a known location that points to
                                 // the component updated flash plugin.
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 #if defined(OS_CHROMEOS)
   FILE_CHROME_OS_COMPONENT_FLASH,  // The location of component updated Flash on
                                    // Chrome OS.
