--- toycars_vehicle_editor/src/VehicleEditorUI.cxx.orig	2009-02-28 14:50:41.000000000 +0000
+++ toycars_vehicle_editor/src/VehicleEditorUI.cxx
@@ -228,7 +228,7 @@ char str[64];
 sprintf(str, "%d", n);
 convexChoice->add(str);
 convexChoice->value(n);
-vehicleObj.getGeometry()->push_back(std::list<Vec2D>::list());
+vehicleObj.getGeometry()->push_back(std::list<Vec2D>());
 spriteView->setConvexChoice(n);
 spriteView->redraw();
 }
