--- t/27sqlite-parser.t.orig	Sun May  9 21:02:06 2004
+++ t/27sqlite-parser.t	Sun May  9 21:02:33 2004
@@ -13,8 +13,8 @@
 
 {
     local $/;
-    open my $fh, "<$file" or die "Can't read file '$file': $!\n";
-    my $data = <$fh>;
+    open FH, "<$file" or die "Can't read file '$file': $!\n";
+    my $data = <FH>;
     my $t = SQL::Translator->new;
     parse($t, $data);
 
