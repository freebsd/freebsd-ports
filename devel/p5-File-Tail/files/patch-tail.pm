--- Tail.pm.debug.orig	2015-08-02 21:47:30.000000000 +0900
+++ Tail.pm.debug	2015-08-21 15:55:07.353518103 +0900
@@ -354,7 +354,7 @@
 
     my $newname;
     if ($oldhandle && $$object{'name_changes_callback'}) {
-	$newname=$$object{'name_changes_callback'}();
+	$newname=$object->{'name_changes_callback'}->();
         $object->{"input"}= $newname;
     } else {
 	$newname=$object->input;
