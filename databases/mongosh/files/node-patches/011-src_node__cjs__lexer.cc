Obtained from:	https://github.com/nodejs/node/commit/59a522af24173b244cb86829de145d46b143a45c

--- a/src/node_cjs_lexer.cc.orig	2026-04-29 21:32:48 UTC
+++ b/src/node_cjs_lexer.cc
@@ -71,14 +71,14 @@ void Parse(const FunctionCallbackInfo<Value>& args) {
   // Convert exports to JS Set
   Local<Set> exports_set = Set::New(isolate);
   for (const auto& exp : analysis.exports) {
-    exports_set->Add(context, CreateString(isolate, exp)).ToLocalChecked();
+    exports_set->Add(context, CreateString(isolate, exp.name)).ToLocalChecked();
   }
 
   // Convert reexports to JS array using batch creation
   LocalVector<Value> reexports_vec(isolate);
   reexports_vec.reserve(analysis.re_exports.size());
   for (const auto& reexp : analysis.re_exports) {
-    reexports_vec.push_back(CreateString(isolate, reexp));
+    reexports_vec.push_back(CreateString(isolate, reexp.name));
   }
 
   // Create result array [exports (Set), reexports (Array)]
