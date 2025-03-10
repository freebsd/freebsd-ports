--- src/Standalone/foldercomb.cpp.orig	2024-09-12 07:10:38 UTC
+++ src/Standalone/foldercomb.cpp
@@ -28,7 +28,7 @@ void FolderComb::initialize(SCANPARA dev_data, CustomM
     changed = true;
     current_item = (Folder)dev_data.Folder;
     user_define_path = dev_data.UserDefinePath.c_str();
-    if(current_item == USER_DEFINE){
+    if(current_item == (Folder)USER_DEFINE){
         QString qStr = user_define_path;
         this->setToolTip(qStr);
     }
@@ -114,7 +114,7 @@ void FolderComb::item_event(int value, SCANPARA* path_
         this->setToolTip(qStr);
     }else if(select_item == OPTIONS){
         this->item_event_options();
-        if(current_item == USER_DEFINE){
+        if(current_item == (Folder)USER_DEFINE){
             qStr = user_define_path;
             path_data->UserDefinePath = (user_define_path.toLocal8Bit()).constData();
             select_item = old_select;
