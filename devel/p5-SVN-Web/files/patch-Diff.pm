--- lib/SVN/Web/Diff.pm	Sun Apr 29 23:22:51 2007
+++ lib/SVN/Web/Diff.pm	Mon Dec 15 02:30:36 2008
@@ -188,8 +188,8 @@
 
     my $mime = $self->{cgi}->param('mime') || 'text/html';
 
-    my %types = ( $rev1 => $ra->check_path($path, $rev1),
-		  $rev2 => $ra->check_path($path, $rev2) );
+    my %types = ( $rev1 => $ra->check_path($self->rpath, $rev1),
+		  $rev2 => $ra->check_path($self->rpath, $rev2) );
 
     SVN::Web::X->throw(error => '(cannot diff nodes of different types: %1 %2 %3)',
 		       vars  => [$path, $rev1, $rev2])
@@ -299,7 +299,7 @@
 
     my $ra   = $self->{repos}{ra};
 
-    if($ra->check_path($path, $rev) == $SVN::Node::none) {
+    if($ra->check_path($self->rpath($path), $rev) == $SVN::Node::none) {
 	SVN::Web::X->throw(
 	    error => '(path %1 does not exist in revision %2)',
