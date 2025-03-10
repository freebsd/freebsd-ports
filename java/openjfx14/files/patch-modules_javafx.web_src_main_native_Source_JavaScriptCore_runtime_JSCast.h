--- modules/javafx.web/src/main/native/Source/JavaScriptCore/runtime/JSCast.h.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/JavaScriptCore/runtime/JSCast.h
@@ -143,7 +143,7 @@ bool inherits(VM& vm, From* from)
 bool inherits(VM& vm, From* from)
 {
     using Dispatcher = InheritsTraits<Target>;
-    return Dispatcher::template inherits(vm, from);
+    return Dispatcher::template inherits<>(vm, from);
 }
 
 } // namespace JSCastingHelpers
@@ -152,7 +152,7 @@ To jsDynamicCast(VM& vm, From* from)
 To jsDynamicCast(VM& vm, From* from)
 {
     using Dispatcher = JSCastingHelpers::InheritsTraits<typename std::remove_cv<typename std::remove_pointer<To>::type>::type>;
-    if (LIKELY(Dispatcher::template inherits(vm, from)))
+    if (LIKELY(Dispatcher::template inherits<>(vm, from)))
         return static_cast<To>(from);
     return nullptr;
 }
