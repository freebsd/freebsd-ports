--- src/MadOptionsDialog.cpp.orig	2017-02-01 03:37:19 UTC
+++ src/MadOptionsDialog.cpp
@@ -1176,7 +1176,7 @@ void MadOptionsDialog::WxTreeCtrl1SelCha
     {
         WxListBoxKeys->Set(g_SelectedCommandItem->keys);
         wxString hint=wxT('[');
-        if(g_SelectedCommandItem->cmddata->menuid_name > 0)
+        if(g_SelectedCommandItem->cmddata->menuid_name)
         {
             hint+= wxString(g_SelectedCommandItem->cmddata->menuid_name);
         }
@@ -1274,7 +1274,7 @@ void MadOptionsDialog::UpdateKeyHint()
             g_CommandItemOfNewKey=tid;
             wxString cmd;
 
-            if(tid->cmddata->menuid_name > 0)
+            if(tid->cmddata->menuid_name)
             {
                 cmd+= wxString(tid->cmddata->menuid_name);
             }
