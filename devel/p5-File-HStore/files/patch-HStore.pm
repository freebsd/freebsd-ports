--- ../File-HStore-0.09-original/lib/File/HStore.pm	Sun Nov 26 11:43:50 2006
+++ lib/File/HStore.pm	Tue Jul 17 18:24:13 2007
@@ -2,8 +2,7 @@
 
 use strict;
 use warnings;
-use Digest::SHA1;
-use Digest::SHA2;
+use Digest::SHA;
 use File::Copy;
 use File::Path;
 
@@ -69,7 +68,7 @@
     my $lSubmitDate;
 
     if ( $self->{digest} eq "FAT" ) {
-        $ldigest = "SHA2";
+        $ldigest = "sha256";
     }
     else {
         $ldigest = $self->{digest};
@@ -191,10 +190,10 @@
     my $sha;
     open( FILED, "$file" ) or die "Unable to open file $file";
     if ( $digestdef eq "SHA1" ) {
-        $sha = Digest::SHA1->new;
+        $sha = Digest::SHA->new("sha1");
     }
     elsif ( $digestdef eq "SHA2" ) {
-        $sha = Digest::SHA2->new;
+        $sha = Digest::SHA->new("sha256");
     }
     else {
         print "unknown digest method";
@@ -242,7 +241,7 @@
 
   use File::HStore;
   my $store = File::HStore ("/tmp/.mystore");
-  
+
   # Add a file in the store
   my $id = $store->add("/foo/bar.txt");
 
@@ -272,7 +271,7 @@
 =head1 METHODS
 
 The object  oriented interface to C<File::HFile> is  described in this
-section.  
+section.
 
 The following methods are provided:
 
@@ -302,7 +301,7 @@
 
 =item $store->remove($hashvalue)
 
-The $hashvalue is the file to be removed from the store. 
+The $hashvalue is the file to be removed from the store.
 
 Return false on success and undef on error.
 
