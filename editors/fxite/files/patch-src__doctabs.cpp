--- src/doctabs.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/doctabs.cpp
@@ -56,7 +56,7 @@ long DocTabs::onDnd(FXObject* sender,FXS
   switch (FXSELTYPE(sel)) {
     case SEL_DND_ENTER: {
       if (getApp()->getCursorWindow()==this) { return 0; }
-      setDragRectangle(0,0,width,height,FALSE);
+      setDragRectangle(0,0,width,height,false);
       if (offeredDNDType(FROM_DRAGNDROP,urilistType)) {
         acceptDrop();
         dnd_accept=true;
@@ -504,7 +504,7 @@ long DocTab::onDnd(FXObject* sender,FXSe
   FXEvent* ev=(FXEvent*)p;
   switch(FXSELTYPE(sel)) {
     case SEL_DND_ENTER:  {
-      setDragRectangle(0,0,width,height,FALSE);
+      setDragRectangle(0,0,width,height,false);
       if (offeredDNDType(FROM_DRAGNDROP,FxteDnDTabType)) {
         acceptDrop();
         dnd_accept=true;
