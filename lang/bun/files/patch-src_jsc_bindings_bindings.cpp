-- Fix build with older JavaScriptCore: JSPromiseReaction::tryGetContext -> reaction->context().

--- src/jsc/bindings/bindings.cpp.orig	2026-05-14 00:25:32 UTC
+++ src/jsc/bindings/bindings.cpp
@@ -2276,7 +2276,7 @@ static void collectAsyncStackFramesFromPromise(JSC::VM
             JSC::JSPromiseReaction* reaction = nullptr;
             if (!dynamicCastValue(reactionsValue, &reaction))
                 return nullptr;
-            JSC::JSValue context = JSC::JSPromiseReaction::tryGetContext(reactionsValue);
+            JSC::JSValue context = reaction->context();
             JSC::InternalFieldTuple* tuple = nullptr;
             if (dynamicCastValue(context, &tuple))
                 context = tuple->getInternalField(0);
