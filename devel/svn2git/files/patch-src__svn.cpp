diff --git a/src/svn.cpp b/src/svn.cpp
index 1aadce9..3d359bb 100644
--- src/svn.cpp
@@ -896,7 +901,7 @@ int SvnRevision::recurse(const char *path, const svn_fs_path_change_t *change,
                                rev_from, changes, current, *match, matchRules, dirpool) == EXIT_FAILURE)
                 return EXIT_FAILURE;
         } else {
-            if (dirent->kind == svn_node_dir) {
+            if (i.value() == svn_node_dir) {
                 qDebug() << current << "rev" << revnum
                          << "did not match any rules; auto-recursing";
                 if (recurse(entry, change, entryFrom.isNull() ? 0 : entryFrom.constData(),
