--- toycars_vehicle_editor/src/VehicleObject.cpp.orig	2009-03-22 19:45:31.000000000 +0000
+++ toycars_vehicle_editor/src/VehicleObject.cpp
@@ -152,7 +152,7 @@ void VehicleObject::loadVehicle(const ch
    short count;
    geometry.clear();
    for (xConvex = xGeometry->FirstChild(); xConvex != NULL; xConvex = xConvex->NextSibling("convex")) {
-      geometry.push_back(std::list<Vec2D>::list());
+      geometry.push_back(std::list<Vec2D>());
       std::list<Vec2D> &convex = geometry.back();
       readPointsFromString(xConvex->FirstChild()->ToText()->Value(), convex, count);
    }
@@ -411,7 +411,7 @@ void VehicleObject::loadSpriteFromDataDi
    short count;
    geometry.clear();
    for (xConvex = xGeometry->FirstChild(); xConvex != NULL; xConvex = xConvex->NextSibling("convex")) {
-      geometry.push_back(std::list<Vec2D>::list());
+      geometry.push_back(std::list<Vec2D>());
       std::list<Vec2D> &convex = geometry.back();
       readPointsFromString(xConvex->FirstChild()->ToText()->Value(), convex, count);
    }
@@ -675,4 +675,4 @@ void VehicleObject::uninstallVehicle(con
    system(str);
    */
 #endif
-}
\ No newline at end of file
+}
