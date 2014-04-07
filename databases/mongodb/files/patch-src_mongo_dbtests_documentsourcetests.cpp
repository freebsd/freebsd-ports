--- ./src/mongo/dbtests/documentsourcetests.cpp.orig	2014-04-07 09:45:28.120368155 +0000
+++ ./src/mongo/dbtests/documentsourcetests.cpp	2014-04-07 09:45:21.592368569 +0000
@@ -583,7 +583,7 @@
         };
 
         struct ValueCmp {
-            bool operator()(const Value& a, const Value& b) {
+            bool operator()(const Value& a, const Value& b) const {
                 return Value::compare( a, b ) < 0;
             }
         };
