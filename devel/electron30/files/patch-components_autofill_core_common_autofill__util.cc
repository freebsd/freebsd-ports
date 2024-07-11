--- components/autofill/core/common/autofill_util.cc.orig	2024-04-15 20:33:53 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -131,7 +131,7 @@ bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
