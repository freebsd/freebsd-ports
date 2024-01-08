--- include/cpprest/json.h.orig	2023-12-05 04:23:31 UTC
+++ include/cpprest/json.h
@@ -737,12 +737,13 @@ class value (private)
     _ASYNCRTIMP void format(std::basic_string<char>& string) const;
 
 #ifdef ENABLE_JSON_VALUE_VISUALIZER
-    explicit value(std::unique_ptr<details::_Value> v, value_type kind) : m_value(std::move(v)), m_kind(kind)
+    explicit value(std::unique_ptr<details::_Value> v, value_type kind);
 #else
-    explicit value(std::unique_ptr<details::_Value> v) : m_value(std::move(v))
+    explicit value(std::unique_ptr<details::_Value> v);
 #endif
-    {
-    }
+public:
+    ~value() noexcept;
+private:
 
     std::unique_ptr<details::_Value> m_value;
 #ifdef ENABLE_JSON_VALUE_VISUALIZER
