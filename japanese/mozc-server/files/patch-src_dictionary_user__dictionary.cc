--- src/dictionary/user_dictionary.cc.orig	2019-03-04 18:35:55 UTC
+++ src/dictionary/user_dictionary.cc
@@ -289,7 +289,7 @@ class UserDictionary::UserDictionaryRelo
     }
 
     auto_register_mode_ = false;
-    dic_->Load(*(storage.get()));
+    dic_->Load(storage.get()->user_dictionary_storage_base);
   }
 
  private:
