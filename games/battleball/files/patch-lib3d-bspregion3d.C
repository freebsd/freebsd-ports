--- lib3d/bspregion3d.C.orig	2011-01-20 12:04:50.000000000 +0100
+++ lib3d/bspregion3d.C	2011-01-20 12:05:08.000000000 +0100
@@ -97,7 +97,7 @@
       xpanel3d& panel= * (xpanel3d *) poly->material_index;
 
       poly->material_index=
-	(int) & *treePanels.insert(treePanels.end(),xpanel3d(*poly,pts,panel));
+	(intptr_t) & *treePanels.insert(treePanels.end(),xpanel3d(*poly,pts,panel));
     }
     MakeBspTreePanels(bspt->negative);
     MakeBspTreePanels(bspt->positive);
