--- ext/json11/json11.cpp.orig	2017-01-18 02:13:48 UTC
+++ ext/json11/json11.cpp
@@ -37,11 +37,20 @@ using std::make_shared;
 using std::initializer_list;
 using std::move;
 
+/* Helper for representing null - just a do-nothing struct, plus comparison
+ * operators so the helpers in JsonValue work. We can't use nullptr_t because
+ * it may not be orderable.
+*/
+struct NullStruct {
+    bool operator==(NullStruct) const { return true; }
+    bool operator<(NullStruct) const { return false; }
+};
+
 /* * * * * * * * * * * * * * * * * * * *
  * Serialization
  */
 
-static void dump(std::nullptr_t, string &out) {
+static void dump(NullStruct, string &out) {
     out += "null";
 }
 
@@ -204,9 +213,9 @@ public:
     explicit JsonObject(Json::object &&value)      : Value(move(value)) {}
 };
 
-class JsonNull final : public Value<Json::NUL, std::nullptr_t> {
+class JsonNull final : public Value<Json::NUL, NullStruct> {
 public:
-    JsonNull() : Value(nullptr) {}
+    JsonNull() : Value({}) {}
 };
 
 /* * * * * * * * * * * * * * * * * * * *
