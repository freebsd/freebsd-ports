--- src/Standalone/addeditpagedialog.cpp.orig	2021-11-25 00:56:56 UTC
+++ src/Standalone/addeditpagedialog.cpp
@@ -89,4 +89,5 @@ bool addeditpageDialog::EditDialog(std::list<imageEdit
     std::list<imageEditInfo> temp_list = {};
     m_jumpImageEditDialog->getInfoList(&temp_list);
     *result_list = temp_list;
+    return true;
 }
