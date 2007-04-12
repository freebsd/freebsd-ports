--- Makefile.PL.orig	Thu Apr 12 13:47:25 2007
+++ Makefile.PL	Thu Apr 12 13:47:36 2007
@@ -7,16 +7,6 @@
 		 'Test::Exception' => 0,
 		);
 
-# Object::Deadly uses Carp::Clan for its runtime. This is a circular
-# dependency and is resolved by installing Carp::Clan without
-# Object::Deadly. Once Object::Deadly is installed, Carp::Clan may use
-# it for testing.
-if (prompt( 'Add Object::Deadly 0.08+ to prerequisites for testing? [Ny]',
-        'no' ) =~ /^y/i
-    )
-{
-    $PREREQ_PM{'Object::Deadly'} = '0.08';
-}
 
 WriteMakefile(
     NAME          => 'Carp::Clan',
