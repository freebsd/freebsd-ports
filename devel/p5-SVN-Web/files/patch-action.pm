--- lib/SVN/Web/action.pm	Sun Apr 29 23:22:51 2007
+++ lib/SVN/Web/action.pm	Mon Dec 15 02:27:15 2008
@@ -241,7 +241,7 @@
     my $ra  = $self->{repos}{ra};
 
     my @log_result;
-    $ra->get_log([$path], $rev, 1, 1, 0, 1,
+    $ra->get_log([$self->rpath($path)], $rev, 1, 1, 0, 1,
                  sub { @log_result = @_; });
 
     return @log_result if wantarray();
@@ -371,5 +371,12 @@
 See L<http://www.perl.com/perl/misc/Artistic.html>
 
 =cut
+
+sub rpath {
+    my ($self,$p) = @_;
+    my $path = $p || $self->{path};
+    $path =~ s{^/}{} if $path;
+    return $path;
+}
 
 1;
