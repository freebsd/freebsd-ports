--- src/celestia/celestiacore.cpp.orig	Thu May  2 10:53:49 2002
+++ src/celestia/celestiacore.cpp	Sat Aug 30 21:32:21 2003
@@ -38,7 +38,6 @@
 #include "celestiacore.h"
 #include <celutil/debug.h>
 
-
 using namespace std;
 
 static const int DragThreshold = 3;
@@ -194,7 +193,7 @@
     sim->setFrame(fav.coordSys, sim->getSelection());
 }
 
-void CelestiaCore::addFavorite(string name, string parentFolder, FavoritesList::const_iterator* iter)
+void CelestiaCore::addFavorite(std::string name, std::string parentFolder, FavoritesList::iterator* iter)
 {
     FavoritesList::iterator pos;
     if(!iter)
@@ -214,7 +213,7 @@
     favorites->insert(pos, fav);
 }
 
-void CelestiaCore::addFavoriteFolder(string name, FavoritesList::const_iterator* iter)
+void CelestiaCore::addFavoriteFolder(std::string name, FavoritesList::iterator* iter)
 {
     FavoritesList::iterator pos;
     if(!iter)
@@ -1138,8 +1137,8 @@
             {
                 double distFromSun = body.getHeliocentricPosition(t).distanceFromOrigin();
                 float planetTemp = sun->getTemperature() * 
-                    (float) (pow(1 - body.getAlbedo(), 0.25) *
-                             sqrt(sun->getRadius() / (2 * distFromSun)));
+                    (float) (pow((float)(1 - body.getAlbedo()),(float)(( 0.25) *
+                             sqrt(sun->getRadius() / (2 * distFromSun)))));
                 overlay << setprecision(0);
                 overlay << "Temperature: " << planetTemp << " K\n";
                 overlay << setprecision(3);
