--- Makefile.PL.orig	2015-04-20 12:59:25 UTC
+++ Makefile.PL
@@ -83,6 +83,6 @@ sub install {
     }
 
     $string = "\n$vars\n$string";
-    $string =~ s{(\t\$\(INST_BIN\) \$\((DESTINSTALL.*?)BIN.+)}{$1\n\t\t\$(INST_SHARE) \$($2SHARE) \\}g;
+    $string =~ s{(\t"?\$\(INST_BIN\)"? "?\$\((DESTINSTALL.*?)BIN.+)"?}{$1\n\t\t\$(INST_SHARE) \$($2SHARE) \\}g;
     return $string;
 }
