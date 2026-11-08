--- google/cloud/internal/async_read_write_stream_tracing.h.orig	2026-11-04 07:02:28 UTC
+++ google/cloud/internal/async_read_write_stream_tracing.h
@@ -120,7 +120,9 @@ class AsyncStreamingReadWriteRpcTracing
     // the lower levels do not create any spans.
     opentelemetry::trace::StartSpanOptions options;
     options.parent = span_->GetContext();
-    auto start_span = internal::MakeSpan(span_name, options);
+    auto start_span = internal::MakeSpan(
+        opentelemetry::nostd::string_view(span_name.data(), span_name.size()),
+        options);
     return std::invoke(StartFunc, *impl_)
         .then([this, ss = std::move(start_span)](future<bool> f) {
           EndSpan(*ss);
