--- apps/ionosphere/VTECMap.hpp.orig	Thu Jan 11 21:38:35 2007
+++ apps/ionosphere/VTECMap.hpp	Thu Jan 11 21:38:51 2007
@@ -193,13 +193,13 @@
       /// Compute the obliquity at a given elevation
       /// @param el elevation in degrees
       /// @return obliquity factor
-   double VTECMap::Obliquity(double el);
+   double Obliquity(double el);
 
 protected:
       /// Allocate the grid array and fill it.
       /// @param refStation reference station
       /// @param factor : 1 for VTEC maps, 2 for MUF maps
-   void VTECMap::reallyMakeGrid(Station& refStation, int factor)
+   void reallyMakeGrid(Station& refStation, int factor)
       throw(Exception);
 
       /// Compute one grid value, using all the data. Called by ComputeMap.
