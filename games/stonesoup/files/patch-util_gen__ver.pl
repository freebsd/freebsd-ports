--- util/gen_ver.pl.orig	2021-10-28 09:37:07 UTC
+++ util/gen_ver.pl
@@ -13,8 +13,7 @@ $mergebase or $mergebase = "";
 
 mkdir dirname($outfile);
 
-$_ = `git describe --tags $mergebase 2> /dev/null`
-    || (open(IN, "<", "$scriptpath/release_ver") ? <IN>
+$_ = (open(IN, "<", "$scriptpath/release_ver") ? <IN>
         : die "No Git, and $scriptpath/release_ver doesn't exist.\n")
     or die "couldn't get the version information\n";
 
