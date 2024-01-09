--- t/11_test_examples.t.orig	2012-08-18 22:03:49 UTC
+++ t/11_test_examples.t
@@ -55,7 +55,7 @@ EOT
 for my $data (@data) {
     my $dir = getcwd();
     chdir("$dir/$data->{path}");
-    my $result = qx{perl $data->{script} 2>&3};
+    my $result = qx{perl $data->{script} 2>/dev/null };
     chdir($dir);
     eq_or_diff(
         $result,
