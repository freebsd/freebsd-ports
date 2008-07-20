--- lib/SVN/Web/Revision.pm.org	2008-07-17 11:24:07.000000000 +0900
+++ lib/SVN/Web/Revision.pm	2008-07-17 11:24:50.000000000 +0900
@@ -211,7 +211,7 @@
         )
         if $rev > $yrev;
 
-    $ra->get_log(['/'], $rev, $rev, 1, 1, 1,
+    $ra->get_log([''], $rev, $rev, 1, 1, 1,
         sub { $self->{REV} = $self->_log(@_) });
 
     $self->_resolve_changed_paths();
