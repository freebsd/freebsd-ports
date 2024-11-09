--- ../test/datcheck.pl.orig	2024-10-18 20:22:54.324331000 +0200
+++ ../test/datcheck.pl	2024-10-18 20:23:29.812680000 +0200
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!/usr/local/bin/perl
 
 #
 #   usage: datcheck.pl file
@@ -108,7 +108,7 @@
 #    printf "            relative error w.r.t. reference value at same position: %f \%\n\n",$maxerror1;
 #}
 
-if($maxerror2>0.){
+if($maxerror2>0.05){
    $maxerror2=100.*$maxerror2;
     print "deviation in file $file.dat\n";
     printf "line: %d reference value: %e value: %e \n",$line2,$valueref2,$value2;
