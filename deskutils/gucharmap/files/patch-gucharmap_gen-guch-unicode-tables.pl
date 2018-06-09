--- gucharmap/gen-guch-unicode-tables.pl.orig	2017-05-09 22:11:10 UTC
+++ gucharmap/gen-guch-unicode-tables.pl
@@ -999,6 +999,7 @@ sub process_versions_txt
         {
             next;
         }
+        next if $raw_version > $v;
 
         my $version = $raw_version;
         $version =~ tr/_/ /;
