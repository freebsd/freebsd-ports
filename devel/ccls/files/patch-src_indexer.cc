https://github.com/MaskRay/ccls/commit/b0d42ad8f2ef22d3a42eee6e7534fc363c018440

--- src/indexer.cc.orig	2019-10-25 01:37:55 UTC
+++ src/indexer.cc
@@ -677,10 +677,13 @@ class IndexDataConsumer : public index::IndexDataConsu
 public:
   IndexDataConsumer(IndexParam &param) : param(param) {}
   void initialize(ASTContext &ctx) override { this->ctx = param.ctx = &ctx; }
-  bool handleDeclOccurence(const Decl *d, index::SymbolRoleSet roles,
-                           ArrayRef<index::SymbolRelation> relations,
-                           SourceLocation src_loc,
-                           ASTNodeInfo ast_node) override {
+#if LLVM_VERSION_MAJOR < 10 // llvmorg-10-init-12036-g3b9715cb219
+# define handleDeclOccurrence handleDeclOccurence
+#endif
+  bool handleDeclOccurrence(const Decl *d, index::SymbolRoleSet roles,
+                            ArrayRef<index::SymbolRelation> relations,
+                            SourceLocation src_loc,
+                            ASTNodeInfo ast_node) override {
     if (!param.no_linkage) {
       if (auto *nd = dyn_cast<NamedDecl>(d); nd && nd->hasLinkage())
         ;
