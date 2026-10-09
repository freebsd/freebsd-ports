--- src/git/diff.rs.orig	2026-10-09 07:14:45 UTC
+++ src/git/diff.rs
@@ -147,6 +147,8 @@ fn git_diff_text(
         "--no-color",
         "--no-ext-diff",
         "--no-textconv",
+        "--src-prefix=a/",
+        "--dst-prefix=b/",
         "-M",
         "-C",
         &context_arg,
@@ -313,6 +315,8 @@ pub(super) fn file_diffs_via_git(
         "--no-color",
         "--no-ext-diff",
         "--no-textconv",
+        "--src-prefix=a/",
+        "--dst-prefix=b/",
         "-M",
         "-C",
         &context_arg,
