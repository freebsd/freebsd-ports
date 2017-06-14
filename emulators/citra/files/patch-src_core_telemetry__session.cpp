https://github.com/citra-emu/citra/issues/2775

--- src/core/telemetry_session.cpp.orig	2017-06-09 04:16:46 UTC
+++ src/core/telemetry_session.cpp
@@ -15,7 +15,7 @@ TelemetrySession::TelemetrySession() {
 
     // Log one-time session start information
     const auto duration{std::chrono::steady_clock::now().time_since_epoch()};
-    const auto start_time{std::chrono::duration_cast<std::chrono::microseconds>(duration).count()};
+    const s64 start_time{std::chrono::duration_cast<std::chrono::microseconds>(duration).count()};
     AddField(Telemetry::FieldType::Session, "StartTime", start_time);
 
     // Log one-time application information
@@ -28,7 +28,7 @@ TelemetrySession::TelemetrySession() {
 TelemetrySession::~TelemetrySession() {
     // Log one-time session end information
     const auto duration{std::chrono::steady_clock::now().time_since_epoch()};
-    const auto end_time{std::chrono::duration_cast<std::chrono::microseconds>(duration).count()};
+    const s64 end_time{std::chrono::duration_cast<std::chrono::microseconds>(duration).count()};
     AddField(Telemetry::FieldType::Session, "EndTime", end_time);
 
     // Complete the session, submitting to web service if necessary
