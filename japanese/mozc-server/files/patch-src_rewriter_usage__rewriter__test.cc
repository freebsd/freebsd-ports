--- src/rewriter/usage_rewriter_test.cc.orig	2019-03-04 18:35:55 UTC
+++ src/rewriter/usage_rewriter_test.cc
@@ -312,7 +312,7 @@ TEST_F(UsageRewriterTest, CommentFromUse
   // Load mock data
   {
     UserDictionaryStorage storage("");
-    UserDictionaryStorage::UserDictionary *dic = storage.add_dictionaries();
+    UserDictionaryStorage::UserDictionary *dic = storage.user_dictionary_storage_base.add_dictionaries();
 
     UserDictionaryStorage::UserDictionaryEntry *entry = dic->add_entries();
     entry->set_key("うま");
@@ -320,7 +320,7 @@ TEST_F(UsageRewriterTest, CommentFromUse
     entry->set_pos(user_dictionary::UserDictionary::NOUN);
     entry->set_comment("アルパカコメント");
 
-    user_dictionary_->Load(storage);
+    user_dictionary_->Load(storage.user_dictionary_storage_base);
   }
 
   // Emulates the conversion of key="うま".
