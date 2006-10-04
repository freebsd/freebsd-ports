--- Makefile.PL.orig	Tue Oct  3 18:20:41 2006
+++ Makefile.PL	Tue Oct  3 18:21:02 2006
@@ -4,13 +4,6 @@
 use ExtUtils::MakeMaker;
 my %PREREQ_PM;
 
-if (prompt( 'Add Object::Deadly 0.08+ to prerequisites for testing? [Ny]',
-        'no' ) =~ /\Ay/imx
-    )
-{
-    $PREREQ_PM{'Object::Deadly'} = '0.08';
-}
-
 WriteMakefile(
     NAME          => 'Carp::Clan',
     AUTHOR        => 'Joshua ben Jore <jjore@cpan.org>',
