Upstream patch: fix automatic conflict resolution for files removed from
the merge target when the merge source and merge target have no proper
common ancestor.  See <https://svn.apache.org/r1839662>.

--- subversion/libsvn_client/conflicts.c.orig	2018-07-12 04:00:15 UTC
+++ subversion/libsvn_client/conflicts.c
@@ -1059,6 +1059,9 @@ find_deleted_rev(void *baton,
     {
       apr_array_header_t *moves;
 
+      if (b->moves_table == NULL)
+        return SVN_NO_ERROR;
+
       moves = apr_hash_get(b->moves_table, &log_entry->revision,
                            sizeof(svn_revnum_t));
       if (moves)
@@ -2223,8 +2226,8 @@ find_operative_moves(apr_array_header_t 
  * If the node was replaced rather than deleted, set *REPLACING_NODE_KIND to
  * the node kind of the replacing node. Else, set it to svn_node_unknown.
  * Only request the log for revisions up to END_REV from the server.
- * If the deleted node was moved, provide heads of move chains in *MOVES.
- * If the node was not moved,set *MOVES to NULL.
+ * If MOVES it not NULL, and the deleted node was moved, provide heads of
+ * move chains in *MOVES, or, if the node was not moved, set *MOVES to NULL.
  */
 static svn_error_t *
 find_revision_for_suspected_deletion(svn_revnum_t *deleted_rev,
@@ -2261,10 +2264,11 @@ find_revision_for_suspected_deletion(svn
                                              scratch_pool));
   victim_abspath = svn_client_conflict_get_local_abspath(conflict);
 
-  SVN_ERR(find_moves_in_revision_range(&moves_table, parent_repos_relpath,
-                                       repos_root_url, repos_uuid,
-                                       victim_abspath, start_rev, end_rev,
-                                       ctx, result_pool, scratch_pool));
+  if (moves)
+    SVN_ERR(find_moves_in_revision_range(&moves_table, parent_repos_relpath,
+                                         repos_root_url, repos_uuid,
+                                         victim_abspath, start_rev, end_rev,
+                                         ctx, result_pool, scratch_pool));
 
   url = svn_path_url_add_component2(repos_root_url, parent_repos_relpath,
                                     scratch_pool);
@@ -2289,7 +2293,8 @@ find_revision_for_suspected_deletion(svn
   b.repos_root_url = repos_root_url;
   b.repos_uuid = repos_uuid;
   b.ctx = ctx;
-  b.moves_table = moves_table;
+  if (moves)
+    b.moves_table = moves_table;
   b.result_pool = result_pool;
   SVN_ERR(svn_ra__dup_session(&b.extra_ra_session, ra_session, NULL,
                               scratch_pool, scratch_pool));
@@ -2319,7 +2324,7 @@ find_revision_for_suspected_deletion(svn
     {
       struct repos_move_info *move = b.move;
 
-      if (move)
+      if (moves && move)
         {
           *deleted_rev = move->rev;
           *deleted_rev_author = move->rev_author;
@@ -2337,7 +2342,8 @@ find_revision_for_suspected_deletion(svn
           *deleted_rev = SVN_INVALID_REVNUM;
           *deleted_rev_author = NULL;
           *replacing_node_kind = svn_node_unknown;
-          *moves = NULL;
+          if (moves)
+            *moves = NULL;
         }
       return SVN_NO_ERROR;
     }
@@ -2346,10 +2352,11 @@ find_revision_for_suspected_deletion(svn
       *deleted_rev = b.deleted_rev;
       *deleted_rev_author = b.deleted_rev_author;
       *replacing_node_kind = b.replacing_node_kind;
-      SVN_ERR(find_operative_moves(moves, moves_table,
-                                   b.deleted_repos_relpath, b.deleted_rev,
-                                   ra_session, repos_root_url,
-                                   result_pool, scratch_pool));
+      if (moves)
+        SVN_ERR(find_operative_moves(moves, moves_table,
+                                     b.deleted_repos_relpath, b.deleted_rev,
+                                     ra_session, repos_root_url,
+                                     result_pool, scratch_pool));
     }
 
   return SVN_NO_ERROR;
@@ -2693,7 +2700,8 @@ conflict_tree_get_details_local_missing(
     end_rev = 0; /* ### We might walk through all of history... */
 
   SVN_ERR(find_revision_for_suspected_deletion(
-            &deleted_rev, &deleted_rev_author, &replacing_node_kind, &moves,
+            &deleted_rev, &deleted_rev_author, &replacing_node_kind,
+            yca_loc ? &moves : NULL,
             conflict, deleted_basename, parent_repos_relpath,
             parent_peg_rev, end_rev, related_repos_relpath, related_peg_rev,
             ctx, conflict->pool, scratch_pool));
