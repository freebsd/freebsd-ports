--- components/autofill/core/common/autofill_util.cc.orig	2024-06-18 21:43:28 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -132,7 +132,7 @@ bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
