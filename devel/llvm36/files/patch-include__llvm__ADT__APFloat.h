--- include/llvm/ADT/APFloat.h.orig	2014-10-10 10:27:22.000000000 +0200
+++ include/llvm/ADT/APFloat.h	2015-08-23 18:33:44.005954000 +0200
@@ -349,7 +349,7 @@ public:
   /// copied from some other APFloat.
   static APFloat copySign(APFloat Value, const APFloat &Sign) {
     Value.copySign(Sign);
-    return std::move(Value);
+    return Value;
   }
 
   /// @}
