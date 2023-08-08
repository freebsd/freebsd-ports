--- src/mongo/db/exec/document_value/value.cpp.orig	2023-06-15 22:07:57 UTC
+++ src/mongo/db/exec/document_value/value.cpp
@@ -59,6 +59,12 @@ using namespace std::string_literals;
 using std::vector;
 using namespace std::string_literals;
 
+RCVector::RCVector() {
+}
+
+RCVector::RCVector(std::vector<Value> v) : vec(std::move(v)) {
+}
+
 void ValueStorage::verifyRefCountingIfShould() const {
     switch (type) {
         case MinKey:
