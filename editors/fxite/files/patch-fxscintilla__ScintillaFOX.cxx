--- fxscintilla/ScintillaFOX.cxx.orig	2013-10-03 09:22:51 UTC
+++ fxscintilla/ScintillaFOX.cxx
@@ -171,7 +171,7 @@ private:
   // From ScintillaBase
   virtual bool ModifyScrollBars(int nMax, int nPage);
   virtual void ReconfigureScrollBars();
-  virtual PRectangle GetClientRectangle();
+  virtual PRectangle GetClientRectangle() const;
   virtual int KeyDefault(int key, int modifiers);
 
   // Popup flag
@@ -662,7 +662,7 @@ sptr_t ScintillaFOX::DirectFunction(
   return sciThis->WndProc(iMessage, wParam, lParam);
 }
 
-PRectangle ScintillaFOX::GetClientRectangle() {
+PRectangle ScintillaFOX::GetClientRectangle() const {
   // Have to call FXScrollArea::getViewportXxxx instead of getViewportXxxx
   // to prevent infinite loop
 #ifdef FOX_1_6
@@ -1256,7 +1256,7 @@ long FXScintilla::onDNDMotion(FXObject* 
   FXDragAction action;
   FXint pos;
   // Scroll into view
-  if(startAutoScroll(ev, TRUE)) return 1;
+  if(startAutoScroll(ev, true)) return 1;
 
   // Handled elsewhere
   if(FXScrollArea::onDNDMotion(sender,sel,ptr)) return 1;
