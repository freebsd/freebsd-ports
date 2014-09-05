--- installConsed.perl.orig	2014-02-11 21:28:45.000000000 +0100
+++ installConsed.perl	2014-08-23 19:27:23.000000000 +0200
@@ -1,4 +1,4 @@
-#!/usr/bin/perl -w
+#!/usr/local/bin/perl -w
 
 # installConsed.perl 
 
@@ -9,7 +9,7 @@
 # and this must be empty and must allow write access
 
 # edit this if you are using a different compiler than gcc
-$CC = "gcc";
+$CC = $ENV{'CC'};
 
 $szVersion = "25.0";
 
@@ -78,9 +78,9 @@
 $szHowToStartOver = "if you have had an error in the midst of this script, you have a problem because some things have been done and others not done.  The cleanest solution is to go back to where nothing is done.  To do that, type:\nrm -rf $szConsedHome/bin\nrm -rf $szConsedHome/lib\nrm -rf $szConsedHome/examples";
 
 
-if ( -e "$szConsedHome/bin" ) {
-   die "$szConsedHome/bin already exists\n$szHowToStartOver\n";
-}
+#if ( -e "$szConsedHome/bin" ) {
+#   die "$szConsedHome/bin already exists\n$szHowToStartOver\n";
+#}
 
 if ( -e "$szConsedHome/lib" ) {
    die "$szConsedHome/lib already exists\n$szHowToStartOver\n";
@@ -91,7 +91,7 @@
 }
 
 
-&doCommand( "mkdir $szConsedHome/bin" );
+#&doCommand( "mkdir $szConsedHome/bin" );
 &doCommand( "mkdir -p $szConsedHome/lib/screenLibs" );
 &doCommand( "mkdir $szConsedHome/examples" );
 &doCommand( "cp $szConsedExecutable $szConsedHome/bin" );
@@ -101,7 +101,7 @@
 print "done\n";
 &doCommand( "cp README.txt $szConsedHome" );
 
-&doCommand( "chmod -R a+w $szConsedHome/examples/*" );
+#&doCommand( "chmod -R a+w $szConsedHome/examples/*" );
 
 &doCommand( "cp $szDownloadDirectory/scripts/* $szConsedHome/bin" );
 
@@ -112,7 +112,7 @@
 @aScreenLibs = split(' ', $szScreenLibs );
 foreach $szScreenFile ( @aScreenLibs ) {
    print "about to cp $szDownloadDirectory/misc/$szScreenFile $szConsedHome/lib/screenLibs\n";
-   &doCommand( "cp $szDownloadDirectory/misc/$szScreenFile $szConsedHome/lib/screenLibs" );
+   &doCommand( "cp $szDownloadDirectory/misc/$szScreenFile $szConsedHome/lib/screenLibs/$szScreenFile.sample" );
 }
 
 
