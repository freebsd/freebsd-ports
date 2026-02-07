--- src/dictionary/user_dictionary_test.cc.orig	2019-03-04 18:35:55 UTC
+++ src/dictionary/user_dictionary_test.cc
@@ -334,9 +334,9 @@ class UserDictionaryTest : public ::test
     std::istringstream is(contents);
     CHECK(is.good());
 
-    storage->Clear();
+    storage->user_dictionary_storage_base.Clear();
     UserDictionaryStorage::UserDictionary *dic
-        = storage->add_dictionaries();
+        = storage->user_dictionary_storage_base.add_dictionaries();
     CHECK(dic);
 
     string line;
@@ -389,7 +389,7 @@ TEST_F(UserDictionaryTest, TestLookupPre
   {
     UserDictionaryStorage storage("");
     UserDictionaryTest::LoadFromString(kUserDictionary0, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   // A normal lookup operation.
@@ -425,7 +425,7 @@ TEST_F(UserDictionaryTest, TestLookupPre
   {
     UserDictionaryStorage storage("");
     LoadFromString(kUserDictionary1, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   // A normal lookup again.
@@ -450,7 +450,7 @@ TEST_F(UserDictionaryTest, TestLookupPre
   {
     UserDictionaryStorage storage("");
     LoadFromString(kUserDictionary0, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   // A normal lookup operation.
@@ -480,7 +480,7 @@ TEST_F(UserDictionaryTest, TestLookupPre
   {
     UserDictionaryStorage storage("");
     LoadFromString(kUserDictionary1, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   // A normal lookup.
@@ -504,7 +504,7 @@ TEST_F(UserDictionaryTest, TestLookupExa
   {
     UserDictionaryStorage storage("");
     LoadFromString(kUserDictionary0, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   // A normal lookup operation.
@@ -540,7 +540,7 @@ TEST_F(UserDictionaryTest, TestLookupExa
     uint64 id = 0;
     EXPECT_TRUE(storage.CreateDictionary("test", &id));
     UserDictionaryStorage::UserDictionary *dic =
-        storage.mutable_dictionaries(0);
+        storage.user_dictionary_storage_base.mutable_dictionaries(0);
 
     // "名詞"
     UserDictionaryStorage::UserDictionaryEntry *entry =
@@ -555,7 +555,7 @@ TEST_F(UserDictionaryTest, TestLookupExa
     entry->set_value("suggest_only");
     entry->set_pos(user_dictionary::UserDictionary::SUGGESTION_ONLY);
 
-    user_dic->Load(storage);
+    user_dic->Load(storage.user_dictionary_storage_base);
   }
 
   // "suggestion_only" should not be looked up.
@@ -577,7 +577,7 @@ TEST_F(UserDictionaryTest, IncognitoMode
   {
     UserDictionaryStorage storage("");
     UserDictionaryTest::LoadFromString(kUserDictionary0, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   TestLookupPrefixHelper(nullptr, 0, "start", 4, *dic);
@@ -612,7 +612,7 @@ TEST_F(UserDictionaryTest, AsyncLoadTest
     uint64 id = 0;
     EXPECT_TRUE(storage.CreateDictionary("test", &id));
     UserDictionaryStorage::UserDictionary *dic =
-        storage.mutable_dictionaries(0);
+        storage.user_dictionary_storage_base.mutable_dictionaries(0);
     for (size_t j = 0; j < 10000; ++j) {
       UserDictionaryStorage::UserDictionaryEntry *entry =
           dic->add_entries();
@@ -681,15 +681,15 @@ TEST_F(UserDictionaryTest, AddToAutoRegi
     UserDictionaryStorage storage(filename);
     EXPECT_TRUE(storage.Load());
     int index = 0;
-    EXPECT_EQ(1, storage.dictionaries_size());
-    EXPECT_EQ(100, storage.dictionaries(index).entries_size());
+    EXPECT_EQ(1, storage.user_dictionary_storage_base.dictionaries_size());
+    EXPECT_EQ(100, storage.user_dictionary_storage_base.dictionaries(index).entries_size());
     for (int i = 0; i < 100; ++i) {
       EXPECT_EQ("key" + std::to_string(i),
-                storage.dictionaries(index).entries(i).key());
+                storage.user_dictionary_storage_base.dictionaries(index).entries(i).key());
       EXPECT_EQ("value" + std::to_string(i),
-                storage.dictionaries(index).entries(i).value());
+                storage.user_dictionary_storage_base.dictionaries(index).entries(i).value());
       EXPECT_EQ(user_dictionary::UserDictionary::NOUN,
-                storage.dictionaries(index).entries(i).pos());
+                storage.user_dictionary_storage_base.dictionaries(index).entries(i).pos());
     }
   }
 
@@ -722,12 +722,12 @@ TEST_F(UserDictionaryTest, AddToAutoRegi
   {
     UserDictionaryStorage storage(filename);
     EXPECT_TRUE(storage.Load());
-    EXPECT_EQ(1, storage.dictionaries_size());
-    EXPECT_EQ(1, storage.dictionaries(0).entries_size());
-    EXPECT_EQ("key", storage.dictionaries(0).entries(0).key());
-    EXPECT_EQ("value", storage.dictionaries(0).entries(0).value());
+    EXPECT_EQ(1, storage.user_dictionary_storage_base.dictionaries_size());
+    EXPECT_EQ(1, storage.user_dictionary_storage_base.dictionaries(0).entries_size());
+    EXPECT_EQ("key", storage.user_dictionary_storage_base.dictionaries(0).entries(0).key());
+    EXPECT_EQ("value", storage.user_dictionary_storage_base.dictionaries(0).entries(0).value());
     EXPECT_EQ(user_dictionary::UserDictionary::NOUN,
-              storage.dictionaries(0).entries(0).pos());
+              storage.user_dictionary_storage_base.dictionaries(0).entries(0).pos());
   }
 }
 
@@ -746,7 +746,7 @@ TEST_F(UserDictionaryTest, TestSuppressi
     uint64 id = 0;
     EXPECT_TRUE(storage.CreateDictionary("test", &id));
     UserDictionaryStorage::UserDictionary *dic =
-        storage.mutable_dictionaries(0);
+        storage.user_dictionary_storage_base.mutable_dictionaries(0);
     for (size_t j = 0; j < 10000; ++j) {
       UserDictionaryStorage::UserDictionaryEntry *entry =
           dic->add_entries();
@@ -770,7 +770,7 @@ TEST_F(UserDictionaryTest, TestSuppressi
 
     suppression_dictionary_->Lock();
     EXPECT_TRUE(suppression_dictionary_->IsLocked());
-    user_dic->Load(storage);
+    user_dic->Load(storage.user_dictionary_storage_base);
     EXPECT_FALSE(suppression_dictionary_->IsLocked());
 
     for (size_t j = 0; j < 10; ++j) {
@@ -782,11 +782,11 @@ TEST_F(UserDictionaryTest, TestSuppressi
 
   // Remove suppression entry
   {
-    storage.Clear();
+    storage.user_dictionary_storage_base.Clear();
     uint64 id = 0;
     EXPECT_TRUE(storage.CreateDictionary("test", &id));
     UserDictionaryStorage::UserDictionary *dic =
-        storage.mutable_dictionaries(0);
+        storage.user_dictionary_storage_base.mutable_dictionaries(0);
     for (size_t j = 0; j < 10000; ++j) {
       UserDictionaryStorage::UserDictionaryEntry *entry =
           dic->add_entries();
@@ -798,7 +798,7 @@ TEST_F(UserDictionaryTest, TestSuppressi
     }
 
     suppression_dictionary_->Lock();
-    user_dic->Load(storage);
+    user_dic->Load(storage.user_dictionary_storage_base);
     EXPECT_FALSE(suppression_dictionary_->IsLocked());
 
     for (size_t j = 0; j < 10; ++j) {
@@ -825,7 +825,7 @@ TEST_F(UserDictionaryTest, TestSuggestio
     uint64 id = 0;
     EXPECT_TRUE(storage.CreateDictionary("test", &id));
     UserDictionaryStorage::UserDictionary *dic =
-        storage.mutable_dictionaries(0);
+        storage.user_dictionary_storage_base.mutable_dictionaries(0);
 
     for (size_t j = 0; j < 10; ++j) {
       UserDictionaryStorage::UserDictionaryEntry *entry =
@@ -845,7 +845,7 @@ TEST_F(UserDictionaryTest, TestSuggestio
       entry->set_pos(user_dictionary::UserDictionary::SUGGESTION_ONLY);
     }
 
-    user_dic->Load(storage);
+    user_dic->Load(storage.user_dictionary_storage_base);
   }
 
   {
@@ -878,7 +878,7 @@ TEST_F(UserDictionaryTest, TestUsageStat
   UserDictionaryStorage storage("");
 
   {
-    UserDictionaryStorage::UserDictionary *dic1 = storage.add_dictionaries();
+    UserDictionaryStorage::UserDictionary *dic1 = storage.user_dictionary_storage_base.add_dictionaries();
     CHECK(dic1);
     UserDictionaryStorage::UserDictionaryEntry *entry;
     entry = dic1->add_entries();
@@ -893,7 +893,7 @@ TEST_F(UserDictionaryTest, TestUsageStat
     entry->set_pos(user_dictionary::UserDictionary::NOUN);
   }
   {
-    UserDictionaryStorage::UserDictionary *dic2 = storage.add_dictionaries();
+    UserDictionaryStorage::UserDictionary *dic2 = storage.user_dictionary_storage_base.add_dictionaries();
     CHECK(dic2);
     UserDictionaryStorage::UserDictionaryEntry *entry;
     entry = dic2->add_entries();
@@ -912,7 +912,7 @@ TEST_F(UserDictionaryTest, TestUsageStat
     entry->set_value("value5");
     entry->set_pos(user_dictionary::UserDictionary::NOUN);
   }
-  dic->Load(storage);
+  dic->Load(storage.user_dictionary_storage_base);
 
   EXPECT_INTEGER_STATS("UserRegisteredWord", 5);
 }
@@ -925,7 +925,7 @@ TEST_F(UserDictionaryTest, LookupComment
   {
     UserDictionaryStorage storage("");
     UserDictionaryTest::LoadFromString(kUserDictionary0, &storage);
-    dic->Load(storage);
+    dic->Load(storage.user_dictionary_storage_base);
   }
 
   // Entry is in user dictionary but has no comment.
