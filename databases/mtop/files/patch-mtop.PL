--- mtop.PL.orig	2004-09-12 22:22:03 UTC
+++ mtop.PL
@@ -1253,7 +1253,7 @@ sub refresh_screen {
             $data =~ s/\.$DOMAIN//o if $col eq "Host";
             if ($col eq "Info") {
                 $data = strip_comments($data);
-                $data = select_fold($data);
+                $data = select_fold($data) if $opt_fold;
             }
             $data =~ s/\s+/ /g;
             $data =~ s/^\s+//;
