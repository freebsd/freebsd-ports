--- lib/SVN/Web/Diff.pm.orig	2007-04-30 03:22:51.000000000 +0800
+++ lib/SVN/Web/Diff.pm	2009-04-21 18:06:59.000000000 +0800
@@ -188,8 +188,11 @@
 
     my $mime = $self->{cgi}->param('mime') || 'text/html';
 
-    my %types = ( $rev1 => $ra->check_path($path, $rev1),
-		  $rev2 => $ra->check_path($path, $rev2) );
+    my $path_getlog = $path;
+    if ($path_getlog eq "/") {$path_getlog = "";}
+    $path_getlog =~ s/^\///;
+    my %types = ( $rev1 => $ra->check_path($path_getlog, $rev1),
+                  $rev2 => $ra->check_path($path_getlog, $rev2) );
 
     SVN::Web::X->throw(error => '(cannot diff nodes of different types: %1 %2 %3)',
 		       vars  => [$path, $rev1, $rev2])
@@ -299,7 +302,10 @@
 
     my $ra   = $self->{repos}{ra};
 
-    if($ra->check_path($path, $rev) == $SVN::Node::none) {
+    my $path_getlog = $path;
+    if ($path_getlog eq "/") {$path_getlog = "";}
+    $path_getlog =~ s/^\///;
+    if($ra->check_path($path_getlog, $rev) == $SVN::Node::none) {
 	SVN::Web::X->throw(
 	    error => '(path %1 does not exist in revision %2)',
             vars  => [$path, $rev],
