--- Makefile.PL.orig	2010-07-12 02:34:56 UTC
+++ Makefile.PL
@@ -8,7 +8,7 @@ WriteMakefile(
     # next two could be from libecasoundc-config --libs --cflags
     # not for now since want it to install w/o libecasoundc-config
     LIBS            => ['-lecasoundc'], 
-    INC             => '',
+    INC             => "-I\${PREFIX}/include",
     ABSTRACT_FROM   => 'Ecasound.pm', 
     AUTHOR          => 'Brad Bowman <eci-perl@bereft.net>', 
     LICENSE         => 'artistic_2',
