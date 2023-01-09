--- lib/external/pattern_language/lib/include/pl/core/ast/ast_node.hpp.orig	2023-01-05 15:11:08 UTC
+++ lib/external/pattern_language/lib/include/pl/core/ast/ast_node.hpp
@@ -15,11 +15,11 @@ namespace pl::core::ast {
 
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
