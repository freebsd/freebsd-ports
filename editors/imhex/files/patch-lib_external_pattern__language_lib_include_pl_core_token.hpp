--- lib/external/pattern_language/lib/include/pl/core/token.hpp.orig	2023-06-24 11:43:14 UTC
+++ lib/external/pattern_language/lib/include/pl/core/token.hpp
@@ -161,7 +161,7 @@ namespace pl::core {
             bool global;
             std::string comment;
 
-            constexpr bool operator==(const DocComment &) const = default;
+            bool operator==(const DocComment &) const = default;
         };
 
         struct Literal : public std::variant<char, bool, u128, i128, double, std::string, std::shared_ptr<ptrn::Pattern>> {
@@ -189,7 +189,7 @@ namespace pl::core {
 
         using ValueTypes = std::variant<Keyword, Identifier, Operator, Literal, ValueType, Separator, DocComment>;
 
-        constexpr Token(Type type, auto value, u32 line, u32 column) : type(type), value(std::move(value)), line(line), column(column) {}
+        inline Token(Type type, auto value, u32 line, u32 column) : type(type), value(std::move(value)), line(line), column(column) {}
 
         [[nodiscard]] constexpr static inline bool isInteger(const ValueType &type) {
             return isUnsigned(type) || isSigned(type);
