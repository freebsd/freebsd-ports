--- src/prediction/user_history_predictor_test.cc.orig	2019-03-04 18:35:55 UTC
+++ src/prediction/user_history_predictor_test.cc
@@ -2222,7 +2222,7 @@ TEST_F(UserHistoryPredictorTest, UserHis
 
   UserHistoryStorage storage1(filename);
 
-  UserHistoryPredictor::Entry *entry = storage1.add_entries();
+  UserHistoryPredictor::Entry *entry = storage1.user_history_base.add_entries();
   CHECK(entry);
   entry->set_key("key");
   entry->set_key("value");
@@ -2230,7 +2230,7 @@ TEST_F(UserHistoryPredictorTest, UserHis
   UserHistoryStorage storage2(filename);
   storage2.Load();
 
-  EXPECT_EQ(storage1.DebugString(), storage2.DebugString());
+  EXPECT_EQ(storage1.user_history_base.DebugString(), storage2.user_history_base.DebugString());
   FileUtil::Unlink(filename);
 }
 
