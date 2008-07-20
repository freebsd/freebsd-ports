--- lib/SVN/Web/View.pm.org	2008-07-17 11:24:12.000000000 +0900
+++ lib/SVN/Web/View.pm	2008-07-17 11:24:53.000000000 +0900
@@ -134,7 +134,10 @@
     my $rev = $act_rev;
 
     # Get the log for this revision of the file
-    $ra->get_log([$path], $rev, $rev, 1, 1, 1,
+    my $path_getlog = $path;
+    if ($path_getlog eq "/") {$path_getlog = "";}
+    $path_getlog =~ s/^\///;
+    $ra->get_log([$path_getlog], $rev, $rev, 1, 1, 1,
         sub { $self->{REV} = $self->_log(@_) });
 
     # Get the text for this revision of the file
