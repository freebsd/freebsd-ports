--- Makefile.PL.orig	2018-08-25 19:54:24 UTC
+++ Makefile.PL
@@ -1,4 +1,3 @@
-use Canary::Stability IO::AIO => 1, 5.008002;
 
 use ExtUtils::MakeMaker;
 
@@ -106,7 +105,7 @@ my $mm = MM->new({
     PM           => {
        'AIO.pm'		=> '$(INST_LIB)/IO/AIO.pm',
     },
-    CONFIGURE_REQUIRES => { ExtUtils::MakeMaker => 6.52, Canary::Stability => 2001 },
+    CONFIGURE_REQUIRES => { ExtUtils::MakeMaker => 6.52 },
     PREREQ_PM => {
        "common::sense" => 0,
     },
