--- lib/external/pattern_language/lib/include/pl/core/ast/ast_node.hpp.orig	2023-04-08 15:28:11 UTC
+++ lib/external/pattern_language/lib/include/pl/core/ast/ast_node.hpp
@@ -16,11 +16,11 @@ namespace pl::core::ast {
 
     class ASTNode : public Cloneable<ASTNode> {
     public:
-        constexpr ASTNode() = default;
+        ASTNode() = default;
 
-        constexpr virtual ~ASTNode() = default;
+        virtual ~ASTNode() = default;
 
-        constexpr ASTNode(const ASTNode &) = default;
+        ASTNode(const ASTNode &) = default;
 
         [[nodiscard]] constexpr u32 getLine() const { return this->m_line; }
         [[nodiscard]] constexpr u32 getColumn() const { return this->m_column; }
