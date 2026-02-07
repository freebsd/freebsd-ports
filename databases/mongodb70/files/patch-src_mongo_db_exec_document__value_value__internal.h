--- src/mongo/db/exec/document_value/value_internal.h.orig	2023-06-15 22:07:57 UTC
+++ src/mongo/db/exec/document_value/value_internal.h
@@ -51,8 +51,8 @@ class RCVector : public RefCountable { (public)
 /// A heap-allocated reference-counted std::vector
 class RCVector : public RefCountable {
 public:
-    RCVector() {}
-    RCVector(std::vector<Value> v) : vec(std::move(v)) {}
+    RCVector();
+    RCVector(std::vector<Value> v);
     std::vector<Value> vec;
 };
 
