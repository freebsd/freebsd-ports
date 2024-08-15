--- Makefile.PL.orig	2024-06-12 01:27:26 UTC
+++ Makefile.PL
@@ -13,14 +13,12 @@ my %args = (
     VERSION_FROM => "lib/Geo/GDAL/FFI.pm",
     LICENSE => "artistic_2",
     CONFIGURE_REQUIRES => {
-        'Alien::gdal' => 0,
     },
     PREREQ_PM => {
         'PkgConfig' => 0.23026,
         'FFI::Platypus' => 0,
         'PDL' => 0,
         'Sort::Versions' => 0,
-        'Alien::gdal' => 0,
     },
     TEST_REQUIRES => {
         'Test::More'          => 0,
