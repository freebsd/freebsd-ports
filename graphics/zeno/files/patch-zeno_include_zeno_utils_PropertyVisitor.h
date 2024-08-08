--- zeno/include/zeno/utils/PropertyVisitor.h.orig	2024-04-25 15:55:29 UTC
+++ zeno/include/zeno/utils/PropertyVisitor.h
@@ -396,12 +396,12 @@ namespace zeno {
                     }
 
                     if constexpr (IsSharedPtr<ValueType>()) {
-                        if (!bIsOptional || Primitive->userData().has<ValueType>(KeyName)) {
-                            ValueRef = Primitive->userData().get<ValueType>(KeyName);
+                        if (!bIsOptional || Primitive->userData().template has<ValueType>(KeyName)) {
+                            ValueRef = Primitive->userData().template get<ValueType>(KeyName);
                         }
                     } else {
-                        if (!bIsOptional || Primitive->userData().has<ValueType>(KeyName)) {
-                            ValueRef = Primitive->userData().get2<ValueType>(KeyName);
+                        if (!bIsOptional || Primitive->userData().template has<ValueType>(KeyName)) {
+                            ValueRef = Primitive->userData().template get2<ValueType>(KeyName);
                         }
                     }
                 };
