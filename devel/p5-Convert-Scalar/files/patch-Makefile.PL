--- Makefile.PL.orig	2017-08-15 05:57:22 UTC
+++ Makefile.PL
@@ -1,6 +1,5 @@
 use ExtUtils::MakeMaker;
 
-use Canary::Stability Convert::Scalar => 1, 5.008;
 
 WriteMakefile(
     dist	=> {
@@ -12,7 +11,6 @@ WriteMakefile(
     VERSION_FROM => "Scalar.pm",
     CONFIGURE_REQUIRES => {
        "ExtUtils::MakeMaker" => 6.6,
-       "Canary::Stability" => 0,
     },
     BUILD_REQUIRES => {
        ExtUtils::ParseXS => 3.28,
