--- src/updatewizard.h.orig	2012-12-02 14:01:31.000000000 +0100
+++ src/updatewizard.h	2012-12-02 14:01:42.000000000 +0100
@@ -50,7 +50,7 @@
         CAutoUpdater& updater,
         QWidget*      parent = NULL);
 
-    UpdateWizard::UpdateWizard( CComponentInfo* );
+    UpdateWizard( CComponentInfo* );
 
     bool shouldShow() const{ return m_showWizard; }
 
