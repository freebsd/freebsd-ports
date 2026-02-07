--- Makefile.PL.orig	2017-02-13 12:26:35 UTC
+++ Makefile.PL
@@ -1,7 +1,6 @@
 use ExtUtils::MakeMaker;
 
 # AnyEvent perl event loop seems to work with 5.6, other modules not
-eval 'use Canary::Stability AnyEvent => 1, 5.008001';
 
 print <<EOF;
 
@@ -38,7 +37,7 @@ WriteMakefile(
 #    PREREQ_PM    => {
 #       Task::Weaken => 0,
 #    },
-    CONFIGURE_REQUIRES => { "ExtUtils::MakeMaker" => 6.52, "Canary::Stability" => 0 },
+    CONFIGURE_REQUIRES => { "ExtUtils::MakeMaker" => 6.52 },
     META_MERGE => {
         recommends => {
            "Task::Weaken"     => 0,
