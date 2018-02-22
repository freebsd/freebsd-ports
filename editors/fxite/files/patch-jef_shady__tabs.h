--- jef/shady_tabs.h.orig	2013-10-03 09:22:51 UTC
+++ jef/shady_tabs.h
@@ -28,7 +28,7 @@ class ShadyTabs: public FXTabBook { (protected)
   void UpdateTabs();
 public:
   long onCmdOpenItem  ( FXObject* sender, FXSelector sel, void* p );
-  void setCurrent(FXint i, FXbool notify=FALSE);
+  void setCurrent(FXint i, FXbool notify=false);
   ShadyTabs(FXComposite* p,FXObject* tgt=NULL, FXSelector sel=0, FXuint opts=TABBOOK_NORMAL,
               FXint x=0, FXint y=0, FXint w=0, FXint h=0, FXint pl=DEFAULT_SPACING,
               FXint pr=DEFAULT_SPACING, FXint pt=DEFAULT_SPACING, FXint pb=DEFAULT_SPACING);
