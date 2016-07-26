--- src/updatewizard.h.orig	2016-07-26 15:06:09 UTC
+++ src/updatewizard.h
@@ -50,7 +50,7 @@ public:
         CAutoUpdater& updater,
         QWidget*      parent = NULL);
 
-    UpdateWizard::UpdateWizard( CComponentInfo* );
+    UpdateWizard( CComponentInfo* );
 
     bool shouldShow() const{ return m_showWizard; }
 
