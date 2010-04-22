--- mtop.PL.orig	2004-09-12 22:22:03.000000000 +0000
+++ mtop.PL	2008-10-04 13:26:58.000000000 +0000
@@ -1253,7 +1253,7 @@
             $data =~ s/\.$DOMAIN//o if $col eq "Host";
             if ($col eq "Info") {
                 $data = strip_comments($data);
-                $data = select_fold($data);
+                $data = select_fold($data) if $opt_fold;
             }
             $data =~ s/\s+/ /g;
             $data =~ s/^\s+//;
