--- Makefile.PL.orig	Mon Aug 30 15:27:33 2004
+++ Makefile.PL	Mon Aug 30 16:18:28 2004
@@ -9,16 +9,16 @@
 my $xrt2d ;
 my @xvfb = "undef";
 my $xvfb;
-my @drivers = qw(gnuplot xrt3d xrt2d xmgrace);
-print "Enter (space separated) graphing drivers to test: [@drivers] ";
-my $drivers = <STDIN>;
-chomp $drivers;
-@drivers = split /\s/,$drivers if $drivers ne '';
+my @drivers = qw(gnuplot xmgrace);
+#print "Enter (space separated) graphing drivers to test: [@drivers] ";
+#my $drivers = <STDIN>;
+#chomp $drivers;
+#@drivers = split /\s/,$drivers if $drivers ne '';
 
 for (@drivers) {
     if (not defined $xvfb and ($_ eq "xrt2d" or $_ eq "xrt3d" or $_ eq "xmgrace")) {
         print "Enter path to X virtual frame buffer(Xvfb): "; 
-        $xvfb = <STDIN>; 
+        $xvfb = "%%X11BASE%%/bin/Xvfb";
         chop $xvfb; 
         @xvfb = $xvfb; 
     }
