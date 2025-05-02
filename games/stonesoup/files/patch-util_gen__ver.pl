--- util/gen_ver.pl.orig	2025-05-02 16:11:38 UTC
+++ util/gen_ver.pl
@@ -21,8 +21,7 @@ mkdir dirname($outfile);
 #
 # Source tarbells distributed as part of a release include this file already
 # generated with the release version.
-$_ = `git describe $mergebase 2> $nullfile`
-    || (open(IN, "<", "$scriptpath/release_ver") ? <IN>
+$_ = (open(IN, "<", "$scriptpath/release_ver") ? <IN>
         : die "Error: Can't get version information: `git describe` failed (no git, no repository, or shallow clone), and $scriptpath/release_ver doesn't exist.\n")
     or die "Error: couldn't get the version information\n";
 
