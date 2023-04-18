--- src/linguist/lupdate/lupdatepreprocessoraction.cpp.orig	2022-12-12 17:11:50 UTC
+++ src/linguist/lupdate/lupdatepreprocessoraction.cpp
@@ -157,7 +157,9 @@ void LupdatePPCallbacks::SourceRangeSkipped(clang::Sou
 void LupdatePPCallbacks::InclusionDirective(clang::SourceLocation /*hashLoc*/,
     const clang::Token & /*includeTok*/, clang::StringRef /*fileName*/, bool /*isAngled*/,
     clang::CharSourceRange /*filenameRange*/,
-#if (LUPDATE_CLANG_VERSION >= LUPDATE_CLANG_VERSION_CHECK(15,0,0))
+#if (LUPDATE_CLANG_VERSION >= LUPDATE_CLANG_VERSION_CHECK(16,0,0))
+    clang::OptionalFileEntryRef file,
+#elif (LUPDATE_CLANG_VERSION >= LUPDATE_CLANG_VERSION_CHECK(15,0,0))
     const clang::Optional<clang::FileEntryRef> file,
 #else
     const clang::FileEntry *file,
