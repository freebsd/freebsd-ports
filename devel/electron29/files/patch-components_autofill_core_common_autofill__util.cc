--- components/autofill/core/common/autofill_util.cc.orig	2024-02-21 00:20:40 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -130,7 +130,7 @@ bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
