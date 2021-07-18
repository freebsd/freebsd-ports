--- components/autofill/core/common/autofill_util.cc.orig	2021-01-07 00:36:29 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -174,7 +174,7 @@ bool SanitizedFieldIsEmpty(const base::string16& value
 }
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   return true;
 #else
