--- scripts/Dpkg/Compression.pm.orig	2016-07-03 19:02:23 UTC
+++ scripts/Dpkg/Compression.pm
@@ -55,7 +55,7 @@ interact with the set of supported compr
 my $COMP = {
     gzip => {
 	file_ext => 'gz',
-	comp_prog => [ 'gzip', '--no-name', '--rsyncable' ],
+	comp_prog => [ 'gzip', '--no-name' ],
 	decomp_prog => [ 'gunzip' ],
 	default_level => 9,
     },
