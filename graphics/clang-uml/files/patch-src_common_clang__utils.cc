--- src/common/clang_utils.cc.orig	2025-01-20 07:36:53 UTC
+++ src/common/clang_utils.cc
@@ -1019,7 +1019,7 @@ clang::RawComment *get_raw_comment(const clang::Source
 
     if (!context.Comments.empty() &&
         context.Comments.getCommentsInFile(file_id) != nullptr) {
-        for (const auto [offset, raw_comment] :
+        for (const auto & [offset, raw_comment] :
             *context.Comments.getCommentsInFile(sm.getFileID(expr_begin))) {
             const auto comment_end_line = sm.getSpellingLineNumber(
                 raw_comment->getSourceRange().getEnd());
