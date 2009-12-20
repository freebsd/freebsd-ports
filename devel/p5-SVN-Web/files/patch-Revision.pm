--- lib/SVN/Web/Revision.pm	Sun Apr 29 23:22:51 2007
+++ lib/SVN/Web/Revision.pm	Sun Dec 14 00:25:26 2008
@@ -211,7 +211,7 @@
         )
         if $rev > $yrev;
 
-    $ra->get_log(['/'], $rev, $rev, 1, 1, 1,
+    $ra->get_log([''], $rev, $rev, 1, 1, 1,
         sub { $self->{REV} = $self->_log(@_) });
 
     $self->_resolve_changed_paths();
