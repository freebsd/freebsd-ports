--- ./Makefile.PL.orig	Mon Sep 25 14:24:05 2006
+++ ./Makefile.PL	Mon Sep 25 14:24:15 2006
@@ -4,10 +4,6 @@
 use ExtUtils::MakeMaker;
 my @PREREQ_PM;
 
-if ( prompt( 'Use Object::Deadly for tests? [Ny]', 'no' ) =~ /\Ay/imx ) {
-    push @PREREQ_PM, ( 'Object::Deadly' => '0.08' );
-}
-
 WriteMakefile(
     NAME          => 'Carp::Clan',
     VERSION_FROM  => 'Clan.pm',
