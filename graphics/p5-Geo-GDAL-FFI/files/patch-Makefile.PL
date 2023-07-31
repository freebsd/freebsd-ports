--- Makefile.PL.orig	2023-07-10 15:20:31 UTC
+++ Makefile.PL
@@ -13,7 +13,7 @@ BEGIN {
     if ($gdal ne 'Alien::gdal' or $@) {
         if ($gdal eq 'Alien::gdal') {
             print "I can't find Alien::gdal.\n";
-            $gdal = '/usr';
+            $gdal = '%%LOCALBASE%%';
         }
         print "Trying GDAL from '$gdal'.\n";
         $have_alien = 0;
@@ -61,7 +61,6 @@ use Config;
     VERSION_FROM => "lib/Geo/GDAL/FFI.pm",
     LICENSE => "artistic_2",
     CONFIGURE_REQUIRES => {
-        Alien::gdal => 0,
     },
     PREREQ_PM => {
         PkgConfig => 0.23026,
@@ -69,7 +68,6 @@ use Config;
         FFI::Platypus::Declare => 0,
         PDL => 0,
         Sort::Versions => 0,
-        Alien::gdal => 0,
     },
     TEST_REQUIRES => {
         'Test::More' => 0,
