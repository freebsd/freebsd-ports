Index: lib/SVK/Command/Propset.pm
===================================================================
--- lib/SVK/Command/Propset.pm	(revision 704)
+++ lib/SVK/Command/Propset.pm	(revision 705)
@@ -31,15 +31,15 @@
 sub do_propset_direct {
     my ($self, $target, $propname, $propvalue) = @_;
 
-    my $fs = $target->{repos}->fs;
     if ($self->{revprop}) {
+	my $fs = $target->{repos}->fs;
         my $rev = (defined($self->{rev}) ? $self->{rev} : $target->{revision});
         $fs->change_rev_prop ($rev, $propname => $propvalue);
         print loc("Property '%1' set on repository revision %2.\n", $propname, $rev);
         return;
     }
 
-    my $root = $fs->revision_root ($fs->youngest_rev);
+    my $root = $target->root;
     my $kind = $root->check_path ($target->path);
 
     die loc("path %1 does not exist.\n", $target->path) if $kind == $SVN::Node::none;
@@ -53,13 +53,13 @@
 	    $editor->change_dir_prop ($editor->{_root_baton}, $propname, $propvalue);
 	}
 	else {
-	    my $baton = $editor->open_directory ($path, 0, -1);
+	    my $baton = $editor->open_directory ($path, 0, $target->{revision});
 	    $editor->change_dir_prop ($baton, $propname, $propvalue);
 	    $editor->close_directory ($baton);
 	}
     }
     else {
-	my $baton = $editor->open_file ($path, 0, -1);
+	my $baton = $editor->open_file ($path, 0, $target->{revision});
 	$editor->change_file_prop ($baton, $propname, $propvalue);
 	$editor->close_file ($baton, undef);
     }
