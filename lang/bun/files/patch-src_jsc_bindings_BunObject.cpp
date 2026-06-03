-- Fix build with older JavaScriptCore: approximate<WTF::WallTime>() -> approximateWallTime().

--- src/jsc/bindings/BunObject.cpp.orig	2026-05-14 00:25:32 UTC
+++ src/jsc/bindings/BunObject.cpp
@@ -665,7 +665,7 @@ JSC_DEFINE_HOST_FUNCTION(functionBunSleep,
 
     if (millisecondsValue.inherits<JSC::DateInstance>()) {
         auto now = MonotonicTime::now();
-        double milliseconds = uncheckedDowncast<JSC::DateInstance>(millisecondsValue)->internalNumber() - now.approximate<WTF::WallTime>().secondsSinceEpoch().milliseconds();
+        double milliseconds = uncheckedDowncast<JSC::DateInstance>(millisecondsValue)->internalNumber() - now.approximateWallTime().secondsSinceEpoch().milliseconds();
         millisecondsValue = JSC::jsNumber(milliseconds > 0 ? std::ceil(milliseconds) : 0);
     }
 
