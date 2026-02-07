--- third_party/perfetto/src/trace_processor/importers/ftrace/v4l2_tracker.cc.orig	2025-03-24 20:50:14 UTC
+++ third_party/perfetto/src/trace_processor/importers/ftrace/v4l2_tracker.cc
@@ -62,7 +62,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kV4l2QbufFieldNumber: {
       V4l2QbufFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = pb_evt.index();
       evt.type = pb_evt.type();
       evt.bytesused = pb_evt.bytesused();
@@ -103,7 +103,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kV4l2DqbufFieldNumber: {
       V4l2DqbufFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = pb_evt.index();
       evt.type = pb_evt.type();
       evt.bytesused = pb_evt.bytesused();
@@ -149,7 +149,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kVb2V4l2BufQueueFieldNumber: {
       Vb2V4l2BufQueueFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
@@ -180,7 +180,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kVb2V4l2BufDoneFieldNumber: {
       Vb2V4l2BufDoneFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
@@ -211,7 +211,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kVb2V4l2QbufFieldNumber: {
       Vb2V4l2QbufFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
@@ -242,7 +242,7 @@ void V4l2Tracker::ParseV4l2Event(uint64_t fld_id,
     case FtraceEvent::kVb2V4l2DqbufFieldNumber: {
       Vb2V4l2DqbufFtraceEvent::Decoder pb_evt(bytes);
       BufferEvent evt;
-      evt.device_minor = pb_evt.minor();
+      evt.device_minor = pb_evt.gminor();
       evt.index = std::nullopt;
       evt.type = std::nullopt;
       evt.bytesused = std::nullopt;
