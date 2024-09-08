--- api/include/opentelemetry/logs/event_logger.h.orig	2024-07-17 20:04:10 UTC
+++ api/include/opentelemetry/logs/event_logger.h
@@ -66,7 +66,7 @@ class EventLogger (public)
     nostd::unique_ptr<LogRecord> log_record = delegate_logger->CreateLogRecord();
 
     IgnoreTraitResult(
-        detail::LogRecordSetterTrait<typename std::decay<ArgumentType>::type>::template Set(
+        detail::LogRecordSetterTrait<typename std::decay<ArgumentType>::type>::template Set<>(
             log_record.get(), std::forward<ArgumentType>(args))...);
 
     EmitEvent(event_name, std::move(log_record));
