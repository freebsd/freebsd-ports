--- lib/SQL/Translator/Producer/XML/SQLFairy.pm.orig	Fri Sep  3 16:27:14 2004
+++ lib/SQL/Translator/Producer/XML/SQLFairy.pm	Sun Oct 24 17:00:03 2004
@@ -349,11 +349,11 @@
     # The order comes from the meths list passed in.
     my @tags;
     my @attr;
-    foreach ( grep { defined $obj->$_ } @meths ) {
+    foreach ( grep { defined $obj->$_() } @meths ) {
         my $what = m/$elements_re/ ? \@tags : \@attr;
         my $val = $_ eq 'extra'
-            ? { $obj->$_ }
-            : $obj->$_;
+            ? { $obj->$_() }
+            : $obj->$_();
         $val = ref $val eq 'ARRAY' ? join(',', @$val) : $val;
         push @$what, $_ => $val;
     };
