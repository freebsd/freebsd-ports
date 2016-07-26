--- src/wizardselectupdatespage.h.orig	2016-07-26 15:06:09 UTC
+++ src/wizardselectupdatespage.h
@@ -58,7 +58,7 @@ public:
     GetChecked(
         std::vector<CComponentInfo*>& vecChecked);
     
-    void WizardSelectUpdatesPage::GetMajorUpdateComponent( std::vector<CComponentInfo*>& vecToUpdate );
+    void GetMajorUpdateComponent( std::vector<CComponentInfo*>& vecToUpdate );
 
 public slots:
 
