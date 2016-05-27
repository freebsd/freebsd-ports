--- tools/openmp/runtime/tools/expand-vars.pl.orig	2014-02-24 10:40:15 UTC
+++ tools/openmp/runtime/tools/expand-vars.pl
@@ -113,7 +113,7 @@ $bulk = read_file( $input );
 
 # Do the replacements.
 $bulk =~
-    s{(?:\$($keyword_rexp)|\$($name_rexp)|\${{(.*?)}})}
+    s{(?:\$($keyword_rexp)|\$($name_rexp)|\$\{\{(.*?)\}\})}
     {
         my $value;
         if ( defined( $1 ) ) {
