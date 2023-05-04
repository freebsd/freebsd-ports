--- chrome/browser/defaults.cc.orig	2022-07-22 17:30:31 UTC
+++ chrome/browser/defaults.cc
@@ -52,7 +52,7 @@ const bool kSyncAutoStarts = true;
 const bool kSyncAutoStarts = false;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const bool kScrollEventChangesTab = true;
 #else
 const bool kScrollEventChangesTab = false;
