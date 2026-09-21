--- src/gui/word_register_dialog/word_register_dialog.cc.orig	2026-09-15 04:45:41 UTC
+++ src/gui/word_register_dialog/word_register_dialog.cc
@@ -298,7 +299,7 @@ WordRegisterDialog::ErrorCode WordRegisterDialog::Save
   }
 
   UserDictionary *dic =
-      session_->mutable_storage()->mutable_dictionaries(index);
+      session_->mutable_storage()->user_dictionary_storage_base.mutable_dictionaries(index);
   CHECK(dic);
 
   if (dic->name() != DictionarycomboBox->currentText().toStdString()) {
