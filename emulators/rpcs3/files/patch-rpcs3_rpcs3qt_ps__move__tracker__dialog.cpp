Fix build with Qt >= 6.9.0

Backported from: https://github.com/RPCS3/rpcs3/commit/600e4604169464c64cbf548e7629e483ad2aad1e

--- rpcs3/rpcs3qt/ps_move_tracker_dialog.cpp.orig	2025-03-30 19:45:32 UTC
+++ rpcs3/rpcs3qt/ps_move_tracker_dialog.cpp
@@ -362,7 +362,7 @@ void ps_move_tracker_dialog::update_min_radius(bool up
 }
 void ps_move_tracker_dialog::update_min_radius(bool update_slider)
 {
-	ui->minRadiusGb->setTitle(tr("Min Radius: %0 %").arg(g_cfg_move.min_radius));
+	ui->minRadiusGb->setTitle(tr("Min Radius: %0 %").arg(g_cfg_move.min_radius.get()));
 
 	if (update_slider)
 	{
@@ -372,7 +372,7 @@ void ps_move_tracker_dialog::update_max_radius(bool up
 
 void ps_move_tracker_dialog::update_max_radius(bool update_slider)
 {
-	ui->maxRadiusGb->setTitle(tr("Max Radius: %0 %").arg(g_cfg_move.max_radius));
+	ui->maxRadiusGb->setTitle(tr("Max Radius: %0 %").arg(g_cfg_move.max_radius.get()));
 
 	if (update_slider)
 	{
