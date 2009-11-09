--- abi-compliance-checker.pl.orig	2009-11-08 14:27:20.000000000 -0500
+++ abi-compliance-checker.pl	2009-11-08 14:33:06.000000000 -0500
@@ -6673,9 +6673,9 @@
     }
     else
     {
-        foreach my $Line (split("\n", `ldconfig -p`))
+        foreach my $Line (split("\n", `ldconfig -r`))
         {
-            if($Line=~/\A[ \t]*([^ \t]+) .* \=\> (.+)\Z/)
+            if($Line=~/\A\t[0-9]*:(.+) \=\> (.+)\Z/)
             {
                 my ($SoCandidate, $Path) = ($1, $2);
                 
