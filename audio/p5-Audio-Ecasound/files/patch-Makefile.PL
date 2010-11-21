--- Makefile.PL.orig	2010-11-21 12:26:33.201477139 +0900
+++ Makefile.PL	2010-11-21 12:26:54.018506858 +0900
@@ -8,7 +8,7 @@
     # next two could be from libecasoundc-config --libs --cflags
     # not for now since want it to install w/o libecasoundc-config
     LIBS            => ['-lecasoundc'], 
-    INC             => '',
+    INC             => "-I\${PREFIX}/include",
     ABSTRACT_FROM   => 'Ecasound.pm', 
     AUTHOR          => 'Brad Bowman <eci-perl@bereft.net>', 
     LICENSE         => 'artistic_2',
