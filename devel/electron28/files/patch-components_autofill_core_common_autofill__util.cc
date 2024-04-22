--- components/autofill/core/common/autofill_util.cc.orig	2023-11-29 21:39:57 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -207,7 +207,7 @@ bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
