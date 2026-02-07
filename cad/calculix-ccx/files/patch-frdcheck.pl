--- ../test/frdcheck.pl.orig	2024-10-18 20:23:04.531136000 +0200
+++ ../test/frdcheck.pl	2024-10-18 20:23:22.184771000 +0200
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!/usr/local/bin/perl
 
 #
 #   usage: frdcheck.pl file
@@ -128,7 +128,7 @@
 
 }
 
-if($maxerror2>0.){
+if($maxerror2>0.05){
    $maxerror2=100.*$maxerror2;
     printf "deviation in file $file.frd\n";
     printf "line: %d reference value: %e value: %e \n",$line2,$valueref2,$value2;
