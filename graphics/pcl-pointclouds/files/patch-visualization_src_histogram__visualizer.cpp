-- fix for VTK-9.7.1

--- visualization/src/histogram_visualizer.cpp.orig	2026-10-25 21:48:40 UTC
+++ visualization/src/histogram_visualizer.cpp
@@ -170,7 +170,7 @@ pcl::visualization::PCLHistogramVisualizer::reCreateAc
 pcl::visualization::PCLHistogramVisualizer::reCreateActor (
     const vtkSmartPointer<vtkDoubleArray> &xy_array, RenWinInteract* renwinupd, const int hsize)
 {
-  renwinupd->ren_->RemoveActor2D (renwinupd->xy_plot_);
+  renwinupd->ren_->RemoveActor (renwinupd->xy_plot_);
   renwinupd->xy_plot_->RemoveAllDataSetInputConnections ();
   
   double min_max[2];
