--- lib/SQL/Translator/Producer/Diagram.pm.orig	Sun May  9 15:00:01 2004
+++ lib/SQL/Translator/Producer/Diagram.pm	Sun May  9 15:09:32 2004
@@ -502,27 +502,27 @@
     #
     debug("imap file = '$imap_file'");
     if ( $imap_file && @imap_coords ) {
-        open my $fh, ">$imap_file" or die "Can't write '$imap_file': $!\n";
-        print $fh qq[<html><body><img src="" usemap="#imap" border="0">\n].
+        open FH, ">$imap_file" or die "Can't write '$imap_file': $!\n";
+        print FH qq[<html><body><img src="" usemap="#imap" border="0">\n].
             qq[<map name="imap">\n];
         for my $rec ( @imap_coords ) {
             my $href = shift @$rec;
-            print $fh q[<area coords="].join(',', @$rec).qq[" href="$href">\n];
+            print FH q[<area coords="].join(',', @$rec).qq[" href="$href">\n];
         } 
-        print $fh qq[</body></html>];
-        close $fh;
+        print FH qq[</body></html>];
+        close FH;
     }
 
     #
     # Print the image.
     #
     if ( $out_file ) {
-        open my $fh, ">$out_file" or die "Can't write '$out_file': $!\n";
-        print $fh $gd->$output_type;
-        close $fh;
+        open FH, ">$out_file" or die "Can't write '$out_file': $!\n";
+        print FH $gd->$output_type();
+        close FH;
     }
     else {
-        return $gd->$output_type;
+        return $gd->$output_type();
     }
 }
 
