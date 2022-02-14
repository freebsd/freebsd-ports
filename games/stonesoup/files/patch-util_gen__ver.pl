--- util/gen_ver.pl.orig	2022-01-25 18:04:53 UTC
+++ util/gen_ver.pl
@@ -20,8 +20,7 @@ mkdir dirname($outfile);
 #
 # Source tarbells distributed as part of a release include this file already
 # generated with the release version.
-$_ = `git describe --tags $mergebase 2> /dev/null`
-    || (open(IN, "<", "$scriptpath/release_ver") ? <IN>
+$_ = (open(IN, "<", "$scriptpath/release_ver") ? <IN>
         : die "Can't get version information: `git describe --tags` failed (no git, no repository, or shallow clone), and $scriptpath/release_ver doesn't exist.\n")
     or die "couldn't get the version information\n";
 
