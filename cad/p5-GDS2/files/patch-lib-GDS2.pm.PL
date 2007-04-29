--- lib/GDS2.pm.PL.orig	Thu May 12 13:19:30 2005
+++ lib/GDS2.pm.PL	Sun Apr 29 15:08:31 2007
@@ -11,19 +11,20 @@
 
 EOP
 
-print "Do you want to use Inline::C code? (y/N): ";
+#print "Do you want to use Inline::C code? (y/N): ";
 
-my $response = <STDIN>;
-if ($response =~ m/^[yY]/)
-{
-    $response = 'yes';
-    print "\nMaking version of GDS2.pm with C code on....";
-}
-else
-{
+#my $response = <STDIN>;
+my $response;
+#if ($response =~ m/^[yY]/)
+#{
+#    $response = 'yes';
+#    print "\nMaking version of GDS2.pm with C code on....";
+#}
+#else
+#{
     $response = 'no';
     print "\nMaking version of GDS2.pm with C code off....";
-}
+#}
 
 rename "lib/GDS2.pm","lib/GDS2.pm.original";
 open(OLD,"<lib/GDS2.pm.original") or die "Unable to read lib/GDS2.pm.original $!";
