-- Fix build with older JavaScriptCore: approximate<WTF::WallTime>() -> approximateWallTime().

--- src/jsc/bindings/BunCPUProfiler.cpp.orig	2026-05-14 00:23:23 UTC
+++ src/jsc/bindings/BunCPUProfiler.cpp
@@ -49,7 +49,7 @@ void startCPUProfiler(JSC::VM& vm)
 {
     // Capture the wall clock time when profiling starts (before creating stopwatch)
     // This will be used as the profile's startTime
-    s_profilingStartTime = MonotonicTime::now().approximate<WTF::WallTime>().secondsSinceEpoch().value() * 1000000.0;
+    s_profilingStartTime = MonotonicTime::now().approximateWallTime().secondsSinceEpoch().value() * 1000000.0;
 
     // Create a stopwatch and start it
     auto stopwatch = WTF::Stopwatch::create();
@@ -364,7 +364,7 @@ void stopCPUProfiler(JSC::VM& vm, WTF::String* outJSON
             auto& stackTrace = stackTraces[idx];
             if (stackTrace.frames.isEmpty()) {
                 samples.append(1);
-                double currentTime = stackTrace.timestamp.approximate<WTF::WallTime>().secondsSinceEpoch().value() * 1000000.0;
+                double currentTime = stackTrace.timestamp.approximateWallTime().secondsSinceEpoch().value() * 1000000.0;
                 double delta = std::max(0.0, currentTime - lastTime);
                 timeDeltas.append(static_cast<long long>(delta));
                 lastTime = currentTime;
@@ -538,7 +538,7 @@ void stopCPUProfiler(JSC::VM& vm, WTF::String* outJSON
 
             samples.append(currentParentId);
 
-            double currentTime = stackTrace.timestamp.approximate<WTF::WallTime>().secondsSinceEpoch().value() * 1000000.0;
+            double currentTime = stackTrace.timestamp.approximateWallTime().secondsSinceEpoch().value() * 1000000.0;
             double delta = std::max(0.0, currentTime - lastTime);
             timeDeltas.append(static_cast<long long>(delta));
             lastTime = currentTime;
@@ -629,7 +629,7 @@ void stopCPUProfiler(JSC::VM& vm, WTF::String* outJSON
         for (size_t idx : sortedIndices) {
             auto& stackTrace = stackTraces[idx];
 
-            double currentTime = stackTrace.timestamp.approximate<WTF::WallTime>().secondsSinceEpoch().value() * 1000000.0;
+            double currentTime = stackTrace.timestamp.approximateWallTime().secondsSinceEpoch().value() * 1000000.0;
             long long deltaUs = static_cast<long long>(std::max(0.0, currentTime - lastTime));
             totalTimeUs += deltaUs;
             lastTime = currentTime;
