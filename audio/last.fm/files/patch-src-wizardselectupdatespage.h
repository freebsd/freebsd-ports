--- src/wizardselectupdatespage.h.orig	2012-12-02 13:59:46.000000000 +0100
+++ src/wizardselectupdatespage.h	2012-12-02 14:00:17.000000000 +0100
@@ -58,7 +58,7 @@
     GetChecked(
         std::vector<CComponentInfo*>& vecChecked);
     
-    void WizardSelectUpdatesPage::GetMajorUpdateComponent( std::vector<CComponentInfo*>& vecToUpdate );
+    void GetMajorUpdateComponent( std::vector<CComponentInfo*>& vecToUpdate );
 
 public slots:
 
