--- Makefile.PL.orig	2012-03-01 11:06:49.000000000 +0000
+++ Makefile.PL	2012-03-01 11:07:14.000000000 +0000
@@ -16,7 +16,7 @@
         'Test::More' => 0.32,
     },
     LIBS                => $libs,
-    CCFLAGS             => $ccflags,
+    INC             	=> $ccflags,
     dist                => { COMPRESS => 'gzip -9f', SUFFIX => 'gz', },
     clean               => { FILES => 'Image-ObjectDetect-*' },
 );
