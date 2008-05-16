--- includes/piece.h.orig	2008-03-18 17:51:15.254937990 +0100
+++ includes/piece.h	2008-03-18 17:51:38.315878696 +0100
@@ -81,12 +81,12 @@
   }
  
   // Methods to display - be carefull, if current_prite is not initialized
-  void Piece::draw(CL_GraphicContext* context = 0)
+  void draw(CL_GraphicContext* context = 0)
     {
       current_sprite -> draw(x, y, context);
     }
 
-  void Piece::draw_mini(CL_GraphicContext* context = 0)
+  void draw_mini(CL_GraphicContext* context = 0)
     {
       mini_sprite -> draw(x, y, context); 
     }
