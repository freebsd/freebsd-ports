--- src/RenderFarmUI/RF_Selection.cpp.orig	2018-07-05 20:35:32 UTC
+++ src/RenderFarmUI/RF_Selection.cpp
@@ -40,7 +40,7 @@ void	RF_SetSelectionMode(int mode)
 	if (mode != rf_Select_Face   && !  gFaceSelection.empty()) {   gFaceSelection.clear(); cleared = 1; }
 	if (mode != rf_Select_PointFeatures && !gPointFeatureSelection.empty()) { gPointFeatureSelection.clear(); cleared = 1; }
 
-	RF_Notifiable::Notify(rf_Cat_Selection, rf_Msg_SelectionModeChanged, (void *) cleared);
+	RF_Notifiable::Notify(rf_Cat_Selection, rf_Msg_SelectionModeChanged, (void *)(size_t) cleared);
 }
 
 
