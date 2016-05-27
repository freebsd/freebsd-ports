--- src/menuMode.cc.orig	2007-04-07 13:16:26 UTC
+++ src/menuMode.cc
@@ -163,7 +163,6 @@ void MenuMode::doSelection() {
   case MENU_EDITOR: GameMode::activate(EditMode::editMode); break;
   }
 }
-inline Real abs(Real v) {return v>0.0?v:-v;}
 
 void MenuMode::idle(Real td) {
   int w,h,i,x,y;
