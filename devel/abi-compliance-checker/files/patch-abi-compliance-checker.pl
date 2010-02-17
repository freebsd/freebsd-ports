--- abi-compliance-checker.pl.orig	2010-02-16 07:13:09.000000000 -0500
+++ abi-compliance-checker.pl	2010-02-17 13:20:46.000000000 -0500
@@ -481,7 +481,7 @@
     return if(not $InfoPath or not -f $InfoPath);
     my $InfoPath_New = $InfoPath.".1";
     #my $Keywords = join("\\|", keys(%check_node));#|grep "$Keywords"
-    system("sed ':a;N;\$!ba;s/\\n[^\@]//g' ".esc($InfoPath)."|sed 's/ [ ]\\+/  /g' > ".esc($InfoPath_New));
+    system("gsed ':a;N;\$!ba;s/\\n[^\@]//g' ".esc($InfoPath)."|gsed 's/ [ ]\\+/  /g' > ".esc($InfoPath_New));
     system("rm", "-fr", $InfoPath);
     #getting info
     open(INFO, $InfoPath_New) || die ("can't open file '\$InfoPath_New\': $!\n");
@@ -7123,9 +7123,9 @@
 
 sub get_solib_default_paths()
 {
-    foreach my $Line (split("\n", `ldconfig -p`))
+    foreach my $Line (split("\n", `ldconfig -r`))
     {
-        if($Line=~/\A[ \t]*([^ \t]+) .* \=\> (.+)\Z/)
+        if($Line=~/\A\t[0-9]*:(.+) \=\> (.+)\Z/)
         {
             $SoLib_DefaultPath{$1} = $2;
         }
