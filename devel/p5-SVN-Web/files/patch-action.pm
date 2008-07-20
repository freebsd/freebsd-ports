--- lib/SVN/Web/action.pm.org	2008-07-17 11:24:18.000000000 +0900
+++ lib/SVN/Web/action.pm	2008-07-17 11:24:57.000000000 +0900
@@ -241,7 +241,10 @@
     my $ra  = $self->{repos}{ra};
 
     my @log_result;
-    $ra->get_log([$path], $rev, 1, 1, 0, 1,
+    my $path_getlog = $path;
+    if ($path_getlog eq "/") {$path_getlog = "";}
+    $path_getlog =~ s/^\///;
+    $ra->get_log([$path_getlog], $rev, 1, 1, 0, 1,
                  sub { @log_result = @_; });
 
     return @log_result if wantarray();
