--- utilities/document/json_document.cc.orig	2015-08-31 20:23:39.000000000 +0200
+++ utilities/document/json_document.cc	2015-09-08 00:10:06.250157000 +0200
@@ -307,7 +307,7 @@ JSONDocument JSONDocument::operator[](co
   assert(foundValue != nullptr);
   // No need to save paths in const objects
   JSONDocument ans(foundValue, false);
-  return std::move(ans);
+  return ans;
 }
 
 size_t JSONDocument::Count() const {
@@ -330,7 +330,7 @@ JSONDocument JSONDocument::operator[](si
   auto arrayVal = reinterpret_cast<fbson::ArrayVal*>(value_);
   auto foundValue = arrayVal->get(static_cast<int>(i));
   JSONDocument ans(foundValue, false);
-  return std::move(ans);
+  return ans;
 }
 
 bool JSONDocument::IsNull() const {
