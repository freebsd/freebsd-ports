--- src/prediction/user_history_predictor.cc.orig	2019-03-04 18:35:55 UTC
+++ src/prediction/user_history_predictor.cc
@@ -291,23 +291,23 @@ bool UserHistoryStorage::Load() {
     return false;
   }
 
-  if (!ParseFromString(input)) {
+  if (!user_history_base.ParseFromString(input)) {
     LOG(ERROR) << "ParseFromString failed. message looks broken";
     return false;
   }
 
-  VLOG(1) << "Loaded user histroy, size=" << entries_size();
+  VLOG(1) << "Loaded user histroy, size=" << user_history_base.entries_size();
   return true;
 }
 
 bool UserHistoryStorage::Save() const {
-  if (entries_size() == 0) {
+  if (user_history_base.entries_size() == 0) {
     LOG(WARNING) << "etries size is 0. Not saved";
     return false;
   }
 
   string output;
-  if (!AppendToString(&output)) {
+  if (!user_history_base.AppendToString(&output)) {
     LOG(ERROR) << "AppendToString failed";
     return false;
   }
@@ -494,12 +494,12 @@ bool UserHistoryPredictor::Load() {
     return false;
   }
 
-  for (size_t i = 0; i < history.entries_size(); ++i) {
-    dic_->Insert(EntryFingerprint(history.entries(i)),
-                 history.entries(i));
+  for (size_t i = 0; i < history.user_history_base.entries_size(); ++i) {
+    dic_->Insert(EntryFingerprint(history.user_history_base.entries(i)),
+                 history.user_history_base.entries(i));
   }
 
-  VLOG(1) << "Loaded user histroy, size=" << history.entries_size();
+  VLOG(1) << "Loaded user histroy, size=" << history.user_history_base.entries_size();
 
   return true;
 }
@@ -521,13 +521,13 @@ bool UserHistoryPredictor::Save() {
 
   UserHistoryStorage history(filename);
   for (const DicElement *elm = tail; elm != nullptr; elm = elm->prev) {
-    history.add_entries()->CopyFrom(elm->value);
+    history.user_history_base.add_entries()->CopyFrom(elm->value);
   }
 
   // Updates usage stats here.
   UsageStats::SetInteger(
       "UserHistoryPredictorEntrySize",
-      static_cast<int>(history.entries_size()));
+      static_cast<int>(history.user_history_base.entries_size()));
 
   if (!history.Save()) {
     LOG(ERROR) << "UserHistoryStorage::Save() failed";
