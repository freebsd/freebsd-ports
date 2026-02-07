--- src/json/json.cpp.orig	2023-12-05 04:23:31 UTC
+++ src/json/json.cpp
@@ -495,3 +495,16 @@ const web::json::details::json_error_category_impl& we
 #endif
     return instance;
 }
+
+#ifdef ENABLE_JSON_VALUE_VISUALIZER
+web::json::value::value(std::unique_ptr<details::_Value> v, value_type kind) : m_value(std::move(v)
+), m_kind(kind)
+#else
+web::json::value::value(std::unique_ptr<details::_Value> v) : m_value(std::move(v))
+#endif
+{
+}
+
+web::json::value::~value() noexcept
+{
+}
