--- t/19sybase-parser.t.orig	Sun May  9 19:14:03 2004
+++ t/19sybase-parser.t	Sun May  9 19:14:34 2004
@@ -17,9 +17,9 @@
 my $data;
 {
     local $/;
-    open my $fh, "<$file" or die "Can't read file '$file': $!\n";
-    $data = <$fh>;
-    close $fh;
+    open FH, "<$file" or die "Can't read file '$file': $!\n";
+    $data = <FH>;
+    close FH;
 }
 
 ok( $data, 'Data' );
