--- src/theme.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/theme.cpp
@@ -644,16 +644,16 @@ void ThemeGUI::SetDemoColors()
 long ThemeGUI::onSelectTheme(FXObject*o, FXSelector sel, void*p)
 {
   AppColors*ac=(AppColors*)(list->getItemData((FXint)((FXival)p)));
-  cw_base->setRGBA(ac->base,TRUE);
-  cw_bord->setRGBA(ac->border,TRUE);
-  cw_fore->setRGBA(ac->fore,TRUE);
-  cw_back->setRGBA(ac->back,TRUE);
-  cw_self->setRGBA(ac->selfore,TRUE);
-  cw_selb->setRGBA(ac->selback,TRUE);
-  cw_menf->setRGBA(ac->selmenutext,TRUE);
-  cw_menb->setRGBA(ac->selmenuback,TRUE);
-  cw_tipf->setRGBA(ac->tipfore,TRUE);
-  cw_tipb->setRGBA(ac->tipback,TRUE);
+  cw_base->setRGBA(ac->base,true);
+  cw_bord->setRGBA(ac->border,true);
+  cw_fore->setRGBA(ac->fore,true);
+  cw_back->setRGBA(ac->back,true);
+  cw_self->setRGBA(ac->selfore,true);
+  cw_selb->setRGBA(ac->selback,true);
+  cw_menf->setRGBA(ac->selmenutext,true);
+  cw_menb->setRGBA(ac->selmenuback,true);
+  cw_tipf->setRGBA(ac->tipfore,true);
+  cw_tipb->setRGBA(ac->tipback,true);
   if (&custom_colors!=ac) {
     memcpy(&custom_colors.base,&ac->base,sizeof(AppColors)-sizeof(char*));
   }
