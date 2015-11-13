--- src/prefdlg_sntx.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/prefdlg_sntx.cpp
@@ -84,7 +84,7 @@ long MyColorWell::onDoubleClicked(FXObje
   colordialog.setSelector(ID_COLORDIALOG);
   colordialog.setRGBA(oldcolor);
   colordialog.setOpaqueOnly(isOpaqueOnly());
-  if(!colordialog.execute(PLACEMENT_SCREEN)) { setRGBA(oldcolor,TRUE); }
+  if(!colordialog.execute(PLACEMENT_SCREEN)) { setRGBA(oldcolor,true); }
   return 1;
 }
 
