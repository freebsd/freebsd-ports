--- lib/SQL/Translator/Producer/GraphViz.pm.orig	Sun May  9 15:10:03 2004
+++ lib/SQL/Translator/Producer/GraphViz.pm	Sun May  9 15:10:53 2004
@@ -378,13 +378,13 @@
     #
     my $output_method = "as_$output_type";
     if ( $out_file ) {
-        open my $fh, ">$out_file" or die "Can't write '$out_file': $!\n";
-        binmode $fh;
-        print $fh $gv->$output_method;
-        close $fh;
+        open FH, ">$out_file" or die "Can't write '$out_file': $!\n";
+        binmode FH;
+        print FH $gv->$output_method();
+        close FH;
     }
     else {
-        return $gv->$output_method;
+        return $gv->$output_method();
     }
 }
 
