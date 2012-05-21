--- src/fileformats/oasis.cpp~	2012-05-21 14:29:24.000000000 -0300
+++ src/fileformats/oasis.cpp	2012-05-21 14:42:42.000000000 -0300
@@ -1896,7 +1896,7 @@
 		element *element_;
 		pointArray pa;
 		pa<<QPoint(modal.placement_x,modal.placement_y);
-		pa<<QPoint(modal.x_space,modal.y_space)*(modal.x_dimension)+QPoint(modal.placement_x,modal.placement_y);
+		pa<<QPoint(modal.x_space,modal.y_space)*static_cast<double>(modal.x_dimension)+QPoint(modal.placement_x,modal.placement_y);
 		pa<<QPoint(modal.placement_x,modal.placement_y);
  		element_=cell_->addCellrefArray(modal.placementCell,pa,modal.x_dimension,1);
  		element_->setName(modal.placement_cell);
