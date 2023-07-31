--- lib/Geo/GDAL/FFI.pm.orig	2023-07-10 15:47:31 UTC
+++ lib/Geo/GDAL/FFI.pm
@@ -1812,7 +1812,6 @@ BEGIN {
         $gdal = Geo::GDAL::gdal->new();
     };
     if ($@) {
-        require Alien::gdal;
         no strict 'subs';
         $gdal = Alien::gdal;
     }
