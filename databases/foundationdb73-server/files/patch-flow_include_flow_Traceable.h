--- flow/include/flow/Traceable.h.orig	2025-07-02 21:14:39 UTC
+++ flow/include/flow/Traceable.h
@@ -255,8 +255,7 @@ struct FormatUsingTraceable : fmt::formatter<std::stri
 // Adapter to redirect fmt::formatter calls to Traceable for a supported type
 template <typename T>
 struct FormatUsingTraceable : fmt::formatter<std::string> {
-	template <typename FormatContext>
-	auto format(const T& val, FormatContext& ctx) {
+	auto format(const T& val, fmt::format_context& ctx) const {
 		return fmt::formatter<std::string>::format(Traceable<T>::toString(val), ctx);
 	}
 };
