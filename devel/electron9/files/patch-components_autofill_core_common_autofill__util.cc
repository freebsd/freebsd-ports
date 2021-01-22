--- components/autofill/core/common/autofill_util.cc.orig	2020-05-26 07:48:19 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -213,7 +213,7 @@ bool SanitizedFieldIsEmpty(const base::string16& value
 }
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return true;
 #else
   return false;
