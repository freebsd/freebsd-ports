--- libs/spirit/test/x3/attribute_type_check.cpp.orig	2026-04-15 14:39:00 UTC
+++ libs/spirit/test/x3/attribute_type_check.cpp
@@ -31,7 +31,7 @@ template <typename Expected, typename Value>
 };
 
 template <typename Expected, typename Value>
-static inline checked_attr_parser<boost::decay_t<Value>, Expected>
+static inline checked_attr_parser<std::decay_t<Value>, Expected>
 checked_attr(Value&& value) { return { std::forward<Value>(value) }; }
 
 // instantiate our type checker
