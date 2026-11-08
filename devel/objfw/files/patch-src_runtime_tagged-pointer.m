--- src/runtime/tagged-pointer.m.orig	2026-08-11 20:07:52 UTC
+++ src/runtime/tagged-pointer.m
@@ -26,9 +26,10 @@
 #define numTaggedPointerBits 4
 #define maxNumTaggedPointerClasses (1 << (numTaggedPointerBits - 1))
 
-Class _objc_taggedPointerClasses[maxNumTaggedPointerClasses];
+Class _objc_taggedPointerClasses[maxNumTaggedPointerClasses]
+    OF_VISIBILITY_INTERNAL;
 static int taggedPointerClassesCount;
-uintptr_t _objc_taggedPointerSecret;
+uintptr_t _objc_taggedPointerSecret OF_VISIBILITY_INTERNAL;
 
 void
 objc_setTaggedPointerSecret(uintptr_t secret)
