--- waeijiro-fpw.pl.orig	Sun Jun  8 22:55:27 2003
+++ waeijiro-fpw.pl	Sun Aug  3 15:24:45 2003
@@ -92,6 +92,7 @@
     my ($line) = @_;
 
     $line =~ s/^■//;
+    $line =~ s///;
     my ($word, $desc) = split(" *: *", $line);
 
     return ($word, $desc);
