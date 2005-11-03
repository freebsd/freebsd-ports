--- Tail.pm.debug.orig Thu Nov  3 12:32:53 2005
+++ Tail.pm.debug      Thu Nov  3 12:33:03 2005
@@ -349,7 +349,7 @@

     my $newname;
     if ($oldhandle && $$object{'name_changes_callback'}) {
-	$newname=$$object{'name_changes_callback'}();
+	$newname=$object->{'name_changes_callback'}->();
     } else {
 	$newname=$object->input;
     }
