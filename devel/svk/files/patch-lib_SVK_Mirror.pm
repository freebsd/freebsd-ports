--- lib/SVK/Mirror.pm.orig	2008-12-13 06:58:21 UTC
+++ lib/SVK/Mirror.pm
@@ -452,7 +452,7 @@ sub get_svkpath {
 }
 
 for my $delegate
-    qw( find_rev_from_changeset find_changeset sync_changeset traverse_new_changesets mirror_changesets get_commit_editor refresh change_rev_prop fromrev source_path relocate )
+    ( qw( find_rev_from_changeset find_changeset sync_changeset traverse_new_changesets mirror_changesets get_commit_editor refresh change_rev_prop fromrev source_path relocate ) )
 {
     no strict 'refs';
     *{$delegate} = sub {
