--- components/autofill/core/common/autofill_util.cc.orig	2023-10-19 19:58:17 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -153,7 +153,7 @@ bool SanitizedFieldIsEmpty(const std::u16string& value
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
