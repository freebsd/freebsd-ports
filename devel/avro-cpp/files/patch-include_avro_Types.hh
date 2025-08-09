--- include/avro/Types.hh.orig	2024-07-26 07:46:40 UTC
+++ include/avro/Types.hh
@@ -113,7 +113,7 @@ struct fmt::formatter<avro::Type> : fmt::formatter<std
 template<>
 struct fmt::formatter<avro::Type> : fmt::formatter<std::string> {
     template<typename FormatContext>
-    auto format(avro::Type t, FormatContext &ctx) {
+    auto format(avro::Type t, FormatContext &ctx) const {
         return fmt::formatter<std::string>::format(avro::toString(t), ctx);
     }
 };
