--- t/050interop-zip-lzma.t.orig	2020-10-31 11:10:56 UTC
+++ t/050interop-zip-lzma.t
@@ -22,7 +22,7 @@ BEGIN {
 use bytes;
 use warnings;
 
-my $P7ZIP ='7z';
+my $P7ZIP ='7zz';
 
 
 sub ExternalP7ZipWorks
@@ -115,7 +115,7 @@ sub memError
 BEGIN {
 
     # Check external 7za exists
-    my $p7zip = '7z';
+    my $p7zip = '7zz';
     for my $dir (reverse split ":", $ENV{PATH})
     {
         $P7ZIP = "$dir/$p7zip"
