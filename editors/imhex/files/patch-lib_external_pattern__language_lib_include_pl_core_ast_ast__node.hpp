--- lib/external/pattern_language/lib/include/pl/core/ast/ast_node.hpp.orig	2023-06-20 14:11:25 UTC
+++ lib/external/pattern_language/lib/include/pl/core/ast/ast_node.hpp
@@ -18,9 +18,9 @@ namespace pl::core::ast {
     public:
         using FunctionResult = std::optional<Token::Literal>;
 
-        constexpr ASTNode() = default;
-        constexpr virtual ~ASTNode() = default;
-        constexpr ASTNode(const ASTNode &) = default;
+        ASTNode() = default;
+        virtual ~ASTNode() = default;
+        ASTNode(const ASTNode &) = default;
 
         [[nodiscard]] u32 getLine() const;
         [[nodiscard]] u32 getColumn() const;
