--- api/include/opentelemetry/logs/logger.h.orig	2024-07-17 20:04:10 UTC
+++ api/include/opentelemetry/logs/logger.h
@@ -73,7 +73,7 @@ class Logger (public)
     }
 
     IgnoreTraitResult(
-        detail::LogRecordSetterTrait<typename std::decay<ArgumentType>::type>::template Set(
+        detail::LogRecordSetterTrait<typename std::decay<ArgumentType>::type>::template Set<>(
             log_record.get(), std::forward<ArgumentType>(args))...);
 
     EmitLogRecord(std::move(log_record));
