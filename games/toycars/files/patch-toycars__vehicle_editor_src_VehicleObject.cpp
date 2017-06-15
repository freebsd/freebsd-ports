--- toycars_vehicle_editor/src/VehicleObject.cpp.orig	2009-03-22 19:45:31 UTC
+++ toycars_vehicle_editor/src/VehicleObject.cpp
@@ -7,6 +7,8 @@
  *
  */
 
+#include <FL/Fl_File_Chooser.H>   // fl_alert
+
 #include "VehicleObject.h"
 #include "ScException.h"
 #include "tinyxml.h"
@@ -152,7 +154,7 @@ void VehicleObject::loadVehicle(const ch
    short count;
    geometry.clear();
    for (xConvex = xGeometry->FirstChild(); xConvex != NULL; xConvex = xConvex->NextSibling("convex")) {
-      geometry.push_back(std::list<Vec2D>::list());
+      geometry.push_back(std::list<Vec2D>());
       std::list<Vec2D> &convex = geometry.back();
       readPointsFromString(xConvex->FirstChild()->ToText()->Value(), convex, count);
    }
@@ -411,7 +413,7 @@ void VehicleObject::loadSpriteFromDataDi
    short count;
    geometry.clear();
    for (xConvex = xGeometry->FirstChild(); xConvex != NULL; xConvex = xConvex->NextSibling("convex")) {
-      geometry.push_back(std::list<Vec2D>::list());
+      geometry.push_back(std::list<Vec2D>());
       std::list<Vec2D> &convex = geometry.back();
       readPointsFromString(xConvex->FirstChild()->ToText()->Value(), convex, count);
    }
@@ -520,8 +522,8 @@ void VehicleObject::loadWheelSpriteFromD
 // installs map into user data directory
 void VehicleObject::installVehicle(const char *name)
 {
-#ifdef WIN32
-   fl_alert("Unfortunately this is unsupported on Windows at this time.\nYou may still install vehicles manually by saving them to a folder and placing it inside the data\\cars directory and editing the carslist.xml file.");
+#if 1
+   fl_alert("Unfortunately this is unsupported at this time.\nYou may still install vehicles manually by saving them to a folder and placing it inside the data\\cars directory and editing the carslist.xml file.");
    return;
 #else
    char fullname[1024];
@@ -600,8 +602,8 @@ void VehicleObject::installVehicle(const
 // nb: doesn't remove car data itself, only remove entry from carslist xml file.
 void VehicleObject::uninstallVehicle(const char *name)
 {
-#ifdef WIN32
-   fl_alert("Unfortunately this is unsupported on Windows at this time.\nYou may still uninstall vehicles manually by removing them from the data\\cars directory and editing the carslist.xml file.");
+#if 1
+   fl_alert("Unfortunately this is unsupported at this time.\nYou may still uninstall vehicles manually by removing them from the data\\cars directory and editing the carslist.xml file.");
    return;
 #else
    char fullname[1024];
@@ -675,4 +677,4 @@ void VehicleObject::uninstallVehicle(con
    system(str);
    */
 #endif
-}
\ No newline at end of file
+}
