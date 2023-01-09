--- lib/external/pattern_language/lib/include/pl/core/ast/ast_node_builtin_type.hpp.orig	2023-01-05 15:12:35 UTC
+++ lib/external/pattern_language/lib/include/pl/core/ast/ast_node_builtin_type.hpp
@@ -15,7 +15,7 @@ namespace pl::core::ast {
 
     class ASTNodeBuiltinType : public ASTNode {
     public:
-        constexpr explicit ASTNodeBuiltinType(Token::ValueType type)
+        explicit ASTNodeBuiltinType(Token::ValueType type)
             : ASTNode(), m_type(type) { }
 
         [[nodiscard]] constexpr const auto &getType() const { return this->m_type; }
