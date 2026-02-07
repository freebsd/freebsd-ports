--- Makefile.PL.orig	2006-08-11 02:38:47 UTC
+++ Makefile.PL
@@ -8,7 +8,7 @@ use ExtUtils::MakeMaker;
 # the contents of the Makefile that is written.
 
 %opts = (
-    'NAME'         => 'App-Trace',
+    'NAME'         => 'App::Trace',
     'DISTNAME'     => 'App-Trace',
     'VERSION_FROM' => 'lib/App/Trace.pm',
     'PREREQ_PM'    => {
