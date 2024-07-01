--- src/mongo/db/exec/document_value/value.cpp.orig	2024-06-19 03:26:19 UTC
+++ src/mongo/db/exec/document_value/value.cpp
@@ -60,6 +60,12 @@ using namespace std::string_literals;
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
