--- include/avro/Node.hh.orig	2024-07-26 07:46:40 UTC
+++ include/avro/Node.hh
@@ -219,7 +219,7 @@ struct fmt::formatter<avro::Name> : fmt::formatter<std
 template<>
 struct fmt::formatter<avro::Name> : fmt::formatter<std::string> {
     template<typename FormatContext>
-    auto format(const avro::Name &n, FormatContext &ctx) {
+    auto format(const avro::Name &n, FormatContext &ctx) const {
         return fmt::formatter<std::string>::format(n.fullname(), ctx);
     }
 };
