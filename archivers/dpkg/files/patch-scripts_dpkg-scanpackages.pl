--- scripts/dpkg-scanpackages.pl.orig	Sun Jun 18 18:22:03 2006
+++ scripts/dpkg-scanpackages.pl	Mon Nov 13 21:30:48 2006
@@ -167,9 +167,9 @@
 	
 	$tv{'Filename'}= "$pathprefix$fn";
 	
-	open(C,"md5sum <$fn |") || die "$fn $!";
-	chop($_=<C>); close(C); $? and die sprintf(_g("\`md5sum < %s' exited with %d"), $fn, $?)."\n";
-	/^([0-9a-f]{32})\s*-?\s*$/ or die sprintf(_g("Strange text from \`md5sum < %s': \`%s'"), $fn, $_)."\n";
+	open(C,"gmd5sum <$fn |") || die "$fn $!";
+	chop($_=<C>); close(C); $? and die sprintf(_g("\`gmd5sum < %s' exited with %d"), $fn, $?)."\n";
+	/^([0-9a-f]{32})\s*-?\s*$/ or die sprintf(_g("Strange text from \`gmd5sum < %s': \`%s'"), $fn, $_)."\n";
 	$tv{'MD5sum'}= $1;
 	
 	my @stat= stat($fn) or die sprintf(_g("Couldn't stat %s: %s"), $fn, $!)."\n";
