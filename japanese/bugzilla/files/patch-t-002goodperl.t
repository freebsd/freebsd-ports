--- t/002goodperl.t~	Mon Feb  3 20:29:23 2003
+++ t/002goodperl.t	Mon Feb  3 20:29:37 2003
@@ -60,7 +60,7 @@
     $file =~ m/.*\.(.*)/;
     my $ext = $1;
 
-    if ($file_line1 !~ /\/usr\/bonsaitools\/bin\/perl/) {
+    if ($file_line1 !~ /\/usr\/bin\/perl/) {
         ok(1,"$file does not have a shebang");	
     } else {
         my $flags;
