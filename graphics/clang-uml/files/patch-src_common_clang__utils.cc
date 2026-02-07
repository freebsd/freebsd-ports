--- src/common/clang_utils.cc.orig	2025-06-29 11:26:26 UTC
+++ src/common/clang_utils.cc
@@ -1023,7 +1023,7 @@ clang::RawComment *get_raw_comment(const clang::Source
     const auto *comments = context.Comments.getCommentsInFile(file_id);
 
     if (has_comments && comments != nullptr) {
-        for (const auto [offset, raw_comment] :
+        for (const auto & [offset, raw_comment] :
             *context.Comments.getCommentsInFile(sm.getFileID(expr_begin))) {
             const auto comment_end_line = sm.getExpansionLineNumber(
                 raw_comment->getSourceRange().getEnd());
