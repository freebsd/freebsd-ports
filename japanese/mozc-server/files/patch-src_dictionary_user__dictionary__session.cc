--- src/dictionary/user_dictionary_session.cc.orig	2019-03-04 18:35:55 UTC
+++ src/dictionary/user_dictionary_session.cc
@@ -69,11 +69,11 @@ class UndoCreateDictionaryCommand : publ
   }
 
   virtual bool RunUndo(mozc::UserDictionaryStorage *storage) {
-    if (storage->dictionaries_size() == 0) {
+    if (storage->user_dictionary_storage_base.dictionaries_size() == 0) {
       return false;
     }
 
-    storage->mutable_dictionaries()->RemoveLast();
+    storage->user_dictionary_storage_base.mutable_dictionaries()->RemoveLast();
     return true;
   }
 
@@ -94,7 +94,7 @@ class UndoDeleteDictionaryCommand : publ
     }
 
     RepeatedPtrField<UserDictionary> *dictionaries =
-        storage->mutable_dictionaries();
+        storage->user_dictionary_storage_base.mutable_dictionaries();
     dictionaries->AddAllocated(dictionary_.release());
 
     // Adjust the position of the reverted dictionary.
@@ -120,10 +120,10 @@ class UndoDeleteDictionaryWithEnsuringNo
   }
 
   virtual bool RunUndo(mozc::UserDictionaryStorage *storage) {
-    if (storage->dictionaries_size() != 1) {
+    if (storage->user_dictionary_storage_base.dictionaries_size() != 1) {
       return false;
     }
-    dictionary_->Swap(storage->mutable_dictionaries(0));
+    dictionary_->Swap(storage->user_dictionary_storage_base.mutable_dictionaries(0));
     return true;
   }
 
@@ -144,7 +144,7 @@ class UndoRenameDictionaryCommand : publ
   virtual bool RunUndo(mozc::UserDictionaryStorage *storage) {
     UserDictionary *dictionary =
         UserDictionaryUtil::GetMutableUserDictionaryById(
-            storage, dictionary_id_);
+            &storage->user_dictionary_storage_base, dictionary_id_);
     if (dictionary == NULL) {
       return false;
     }
@@ -169,7 +169,7 @@ class UndoAddEntryCommand : public UserD
   virtual bool RunUndo(mozc::UserDictionaryStorage *storage) {
     UserDictionary *dictionary =
         UserDictionaryUtil::GetMutableUserDictionaryById(
-            storage, dictionary_id_);
+            &storage->user_dictionary_storage_base, dictionary_id_);
     if (dictionary == NULL || dictionary->entries_size() == 0) {
       return false;
     }
@@ -195,7 +195,7 @@ class UndoEditEntryCommand : public User
   virtual bool RunUndo(mozc::UserDictionaryStorage *storage) {
     UserDictionary *dictionary =
         UserDictionaryUtil::GetMutableUserDictionaryById(
-            storage, dictionary_id_);
+            &storage->user_dictionary_storage_base, dictionary_id_);
     if (dictionary == NULL ||
         index_ < 0 || dictionary->entries_size() <= index_) {
       return false;
@@ -240,7 +240,7 @@ class UndoDeleteEntryCommand : public Us
   virtual bool RunUndo(mozc::UserDictionaryStorage *storage) {
     UserDictionary *dictionary =
         UserDictionaryUtil::GetMutableUserDictionaryById(
-            storage, dictionary_id_);
+            &storage->user_dictionary_storage_base, dictionary_id_);
     if (dictionary == NULL) {
       return false;
     }
@@ -306,7 +306,7 @@ class UndoImportFromStringCommand : publ
   virtual bool RunUndo(mozc::UserDictionaryStorage *storage) {
     UserDictionary *dictionary =
         UserDictionaryUtil::GetMutableUserDictionaryById(
-            storage, dictionary_id_);
+            &storage->user_dictionary_storage_base, dictionary_id_);
     if (dictionary == NULL) {
       return false;
     }
@@ -345,7 +345,7 @@ UserDictionarySession::~UserDictionarySe
 
 // TODO(hidehiko) move this to header.
 const UserDictionaryStorage &UserDictionarySession::storage() const {
-  return *storage_;
+  return storage_->user_dictionary_storage_base;
 }
 mozc::UserDictionaryStorage *UserDictionarySession::mutable_storage() {
   return storage_.get();
@@ -464,7 +464,7 @@ UserDictionaryCommandStatus::Status User
     const string &dictionary_name, uint64 *new_dictionary_id) {
   UserDictionaryCommandStatus::Status status =
       UserDictionaryUtil::CreateDictionary(
-          storage_.get(), dictionary_name, new_dictionary_id);
+          &storage_->user_dictionary_storage_base, dictionary_name, new_dictionary_id);
   if (status == UserDictionaryCommandStatus::USER_DICTIONARY_COMMAND_SUCCESS) {
     AddUndoCommand(new UndoCreateDictionaryCommand);
   }
@@ -488,7 +488,7 @@ UserDictionarySession::DeleteDictionaryI
   int original_index;
   UserDictionary *deleted_dictionary;
   if (!UserDictionaryUtil::DeleteDictionary(
-          storage_.get(), dictionary_id,
+          &storage_->user_dictionary_storage_base, dictionary_id,
           &original_index, &deleted_dictionary)) {
     // Failed to delete the dictionary.
     return UserDictionaryCommandStatus::UNKNOWN_DICTIONARY_ID;
@@ -510,7 +510,7 @@ UserDictionaryCommandStatus::Status User
     uint64 dictionary_id, const string &dictionary_name) {
   string original_name;
   const UserDictionary *dictionary =
-      UserDictionaryUtil::GetUserDictionaryById(*storage_, dictionary_id);
+      UserDictionaryUtil::GetUserDictionaryById(storage_->user_dictionary_storage_base, dictionary_id);
   if (dictionary != NULL) {
     // Note that if dictionary is null, it means the dictionary_id is invalid
     // so following RenameDictionary will fail, and error handling is done
@@ -547,7 +547,7 @@ UserDictionaryCommandStatus::Status User
     uint64 dictionary_id, const UserDictionary::Entry &entry) {
   UserDictionary *dictionary =
       UserDictionaryUtil::GetMutableUserDictionaryById(
-          storage_.get(), dictionary_id);
+          &storage_->user_dictionary_storage_base, dictionary_id);
   if (dictionary == NULL) {
     return UserDictionaryCommandStatus::UNKNOWN_DICTIONARY_ID;
   }
@@ -575,7 +575,7 @@ UserDictionaryCommandStatus::Status User
     uint64 dictionary_id, int index, const UserDictionary::Entry &entry) {
   UserDictionary *dictionary =
       UserDictionaryUtil::GetMutableUserDictionaryById(
-          storage_.get(), dictionary_id);
+          &storage_->user_dictionary_storage_base, dictionary_id);
   if (dictionary == NULL) {
     return UserDictionaryCommandStatus::UNKNOWN_DICTIONARY_ID;
   }
@@ -604,7 +604,7 @@ UserDictionaryCommandStatus::Status User
     uint64 dictionary_id, const std::vector<int> &index_list) {
   UserDictionary *dictionary =
       UserDictionaryUtil::GetMutableUserDictionaryById(
-          storage_.get(), dictionary_id);
+          &storage_->user_dictionary_storage_base, dictionary_id);
   if (dictionary == NULL) {
     return UserDictionaryCommandStatus::UNKNOWN_DICTIONARY_ID;
   }
@@ -644,7 +644,7 @@ UserDictionaryCommandStatus::Status User
     uint64 dictionary_id, const string &data) {
   UserDictionary *dictionary =
       UserDictionaryUtil::GetMutableUserDictionaryById(
-          storage_.get(), dictionary_id);
+          &storage_->user_dictionary_storage_base, dictionary_id);
   if (dictionary == NULL) {
     return UserDictionaryCommandStatus::UNKNOWN_DICTIONARY_ID;
   }
@@ -699,7 +699,7 @@ UserDictionarySession::ImportToNewDictio
     uint64 *new_dictionary_id) {
   UserDictionaryCommandStatus::Status status =
       UserDictionaryUtil::CreateDictionary(
-          storage_.get(), dictionary_name, new_dictionary_id);
+          &storage_->user_dictionary_storage_base, dictionary_name, new_dictionary_id);
   if (status != UserDictionaryCommandStatus::USER_DICTIONARY_COMMAND_SUCCESS) {
     return status;
   }
@@ -709,7 +709,7 @@ UserDictionarySession::ImportToNewDictio
 
   UserDictionary *dictionary =
       UserDictionaryUtil::GetMutableUserDictionaryById(
-          storage_.get(), *new_dictionary_id);
+          &storage_->user_dictionary_storage_base, *new_dictionary_id);
   if (dictionary == NULL) {
     // The dictionary should be always found.
     return UserDictionaryCommandStatus::UNKNOWN_ERROR;
@@ -719,7 +719,7 @@ UserDictionarySession::ImportToNewDictio
 }
 
 bool UserDictionarySession::EnsureNonEmptyStorage() {
-  if (storage_->dictionaries_size() > 0) {
+  if (storage_->user_dictionary_storage_base.dictionaries_size() > 0) {
     // The storage already has at least one dictionary. Do nothing.
     return false;
   }
@@ -728,7 +728,7 @@ bool UserDictionarySession::EnsureNonEmp
   uint64 new_dictionary_id;
   UserDictionaryCommandStatus::Status status =
       UserDictionaryUtil::CreateDictionary(
-          storage_.get(), default_dictionary_name_, &new_dictionary_id);
+          &storage_->user_dictionary_storage_base, default_dictionary_name_, &new_dictionary_id);
   CHECK_EQ(
       status, UserDictionaryCommandStatus::USER_DICTIONARY_COMMAND_SUCCESS);
   return true;
@@ -755,7 +755,7 @@ void UserDictionarySession::AddUndoComma
 
 void UserDictionarySession::ClearDictionariesAndUndoHistory() {
   ScopedUserDictionaryLocker l(storage_.get());
-  storage_->clear_dictionaries();
+  storage_->user_dictionary_storage_base.clear_dictionaries();
   ClearUndoHistory();
 }
 
