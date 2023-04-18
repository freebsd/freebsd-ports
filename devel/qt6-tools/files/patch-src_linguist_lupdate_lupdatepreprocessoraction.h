--- src/linguist/lupdate/lupdatepreprocessoraction.h.orig	2022-12-12 17:11:50 UTC
+++ src/linguist/lupdate/lupdatepreprocessoraction.h
@@ -52,7 +52,9 @@ class LupdatePPCallbacks : public clang::PPCallbacks (
     void InclusionDirective(clang::SourceLocation /*hashLoc*/, const clang::Token &/*includeTok*/,
                             clang::StringRef /*fileName*/, bool /*isAngled*/,
                             clang::CharSourceRange /*filenameRange*/,
-#if (LUPDATE_CLANG_VERSION >= LUPDATE_CLANG_VERSION_CHECK(15,0,0))
+#if (LUPDATE_CLANG_VERSION >= LUPDATE_CLANG_VERSION_CHECK(16,0,0))
+                            clang::OptionalFileEntryRef file,
+#elif (LUPDATE_CLANG_VERSION >= LUPDATE_CLANG_VERSION_CHECK(15,0,0))
                             const clang::Optional<clang::FileEntryRef> file,
 #else
                             const clang::FileEntry *file,
