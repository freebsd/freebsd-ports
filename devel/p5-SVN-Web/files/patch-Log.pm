--- lib/SVN/Web/Log.pm	Sun Apr 29 23:22:51 2007
+++ lib/SVN/Web/Log.pm	Mon Dec 15 02:32:02 2008
@@ -214,7 +215,7 @@
 	# entries then we're on the last page.
 	#
 	# If we're not on the last page then pop off the extra log entry
-	$ra->get_log([$path], $rev, 1, $limit + 1, 1, 1,
+	$ra->get_log([$self->rpath], $rev, 1, $limit + 1, 1, 1,
 		     sub { $self->_log(@_) });
 
 	$at_oldest = @{ $self->{REVS} } <= $limit;
@@ -222,7 +223,7 @@
 	pop @{ $self->{REVS} } unless $at_oldest;
     } else {
 	# We must be displaying to the oldest rev, so no paging required
-	$ra->get_log([$path], $rev, 1, $limit, 1, 1,
+	$ra->get_log([$self->rpath], $rev, 1, $limit, 1, 1,
 		     sub { $self->_log(@_) });
 
 	$at_oldest = 1;
