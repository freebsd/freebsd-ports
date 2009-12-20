--- lib/SVN/Web/View.pm	Sun Apr 29 23:22:51 2007
+++ lib/SVN/Web/View.pm	Mon Dec 15 02:29:44 2008
@@ -134,7 +134,7 @@
     my $rev = $act_rev;
 
     # Get the log for this revision of the file
-    $ra->get_log([$path], $rev, $rev, 1, 1, 1,
+    $ra->get_log([$self->rpath], $rev, $rev, 1, 1, 1,
         sub { $self->{REV} = $self->_log(@_) });
 
     # Get the text for this revision of the file
