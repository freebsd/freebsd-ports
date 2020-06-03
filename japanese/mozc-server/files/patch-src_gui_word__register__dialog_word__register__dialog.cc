--- src/gui/word_register_dialog/word_register_dialog.cc.orig	2019-03-04 18:35:55 UTC
+++ src/gui/word_register_dialog/word_register_dialog.cc
@@ -298,7 +298,7 @@ WordRegisterDialog::ErrorCode WordRegist
   }
 
   UserDictionary *dic =
-      session_->mutable_storage()->mutable_dictionaries(index);
+      session_->mutable_storage()->user_dictionary_storage_base.mutable_dictionaries(index);
   CHECK(dic);
 
   if (dic->name() != DictionarycomboBox->currentText().toStdString()) {
