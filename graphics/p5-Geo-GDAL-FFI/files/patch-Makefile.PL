--- Makefile.PL.orig	2021-03-16 05:32:47 UTC
+++ Makefile.PL
@@ -1,6 +1,4 @@
-use Alien::gdal;
 use ExtUtils::MakeMaker;
-use Alien::Base::Wrapper qw( Alien::gdal !export );
 use Config;
  
 WriteMakefile(
@@ -9,15 +7,12 @@ WriteMakefile(
     ABSTRACT_FROM => "lib/Geo/GDAL/FFI.pm",
     VERSION_FROM => "lib/Geo/GDAL/FFI.pm",
     LICENSE => "artistic_2",
-    Alien::Base::Wrapper->mm_args,
     CONFIGURE_REQUIRES => {
-        'Alien::gdal' => 0
     },
     PREREQ_PM => {
         'PkgConfig' => 0.23026,
         'FFI::Platypus' => 0,
         'FFI::Platypus::Declare' => 0,
-        'Alien::gdal' => 0,
         'PDL' => 0
     },
     TEST_REQUIRES => {
