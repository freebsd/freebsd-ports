--- scripts/addReads2Consed.perl.orig	2007-09-26 04:02:19.000000000 +0900
+++ scripts/addReads2Consed.perl	2007-12-11 17:27:20.000000000 +0900
@@ -71,7 +71,7 @@
 $szVectorFile = $szConsedHome . "/lib/screenLibs/vector.seq";
 
 # change this to reflect wherever you put the phred parameter file
-$szPhredParameterFile = $szConsedHome . "/lib/phredpar.dat";
+$szPhredParameterFile = $szConsedHome . "/etc/PhredPar/phredpar.dat";
 #$szPhredParameterFile = "/usr/local/common/lib/PhredPar/phredpar.dat";
 #$szPhredParameterFile = "/usr/local/etc/PhredPar/phredpar.dat";
 
