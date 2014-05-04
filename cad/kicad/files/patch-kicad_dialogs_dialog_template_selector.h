--- kicad/dialogs/dialog_template_selector.h.orig	2012-12-18 16:03:30.000000000 +0100
+++ kicad/dialogs/dialog_template_selector.h	2014-05-02 10:30:14.000000000 +0200
@@ -72,7 +72,7 @@
 class DIALOG_TEMPLATE_SELECTOR : public DIALOG_TEMPLATE_SELECTOR_BASE
 {
 protected:
-    vector<TEMPLATE_SELECTION_PANEL*> m_panels;
+    std::vector<TEMPLATE_SELECTION_PANEL*> m_panels;
     void AddTemplate( int aPage, PROJECT_TEMPLATE* aTemplate );
     TEMPLATE_WIDGET* m_selectedWidget;
 
