--- lib/external/pattern_language/lib/include/pl/core/ast/ast_node_bitfield.hpp.orig	2022-08-18 14:31:33 UTC
+++ lib/external/pattern_language/lib/include/pl/core/ast/ast_node_bitfield.hpp
@@ -86,7 +86,6 @@ namespace pl::core::ast {
 
     private:
         std::vector<std::unique_ptr<ASTNode>> m_entries;
-        mutable size_t m_bitOffset = 0x00;
     };
 
 }
\ No newline at end of file
