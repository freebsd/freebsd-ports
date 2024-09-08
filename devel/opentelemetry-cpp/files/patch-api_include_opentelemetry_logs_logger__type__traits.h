--- api/include/opentelemetry/logs/logger_type_traits.h.orig	2024-07-17 20:04:10 UTC
+++ api/include/opentelemetry/logs/logger_type_traits.h
@@ -166,7 +166,7 @@ struct LogRecordSetterTrait
                 * = nullptr>
   inline static LogRecord *Set(LogRecord *log_record, ArgumentType &&arg) noexcept
   {
-    return LogRecordSetterTrait<common::KeyValueIterable>::template Set(
+    return LogRecordSetterTrait<common::KeyValueIterable>::template Set<>(
         log_record, std::forward<ArgumentType>(arg));
   }
 
