--- lib/SVN/Web/Log.pm.org	2008-07-17 11:23:59.000000000 +0900
+++ lib/SVN/Web/Log.pm	2008-07-17 11:27:14.000000000 +0900
@@ -214,7 +214,10 @@
 	# entries then we're on the last page.
 	#
 	# If we're not on the last page then pop off the extra log entry
-	$ra->get_log([$path], $rev, 1, $limit + 1, 1, 1,
+	my $path_getlog = $path;
+	if ($path_getlog eq "/") {$path_getlog = "";}
+	$path_getlog =~ s/^\///;
+	$ra->get_log([$path_getlog], $rev, 1, $limit + 1, 1, 1,
 		     sub { $self->_log(@_) });
 
 	$at_oldest = @{ $self->{REVS} } <= $limit;
@@ -222,6 +225,7 @@
 	pop @{ $self->{REVS} } unless $at_oldest;
     } else {
 	# We must be displaying to the oldest rev, so no paging required
+	if($path eq "/") {$path = "";}
 	$ra->get_log([$path], $rev, 1, $limit, 1, 1,
 		     sub { $self->_log(@_) });
 
