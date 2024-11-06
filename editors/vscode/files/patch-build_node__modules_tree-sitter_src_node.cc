--- build/node_modules/tree-sitter/src/node.cc.orig	2024-10-11 07:51:19 UTC
+++ build/node_modules/tree-sitter/src/node.cc
@@ -479,9 +479,9 @@ struct SymbolSet {
 }
 
 struct SymbolSet {
-  std::basic_string<TSSymbol> symbols;
-  void add(TSSymbol symbol) { symbols += symbol; }
-  bool contains(TSSymbol symbol) { return symbols.find(symbol) != symbols.npos; }
+  std::vector<TSSymbol> symbols;
+  void add(TSSymbol symbol) { symbols.push_back(symbol); }
+  bool contains(TSSymbol symbol) const { return std::find(symbols.begin(), symbols.end(), symbol) != symbols.end(); }
 };
 
 bool symbol_set_from_js(SymbolSet *symbols, const Local<Value> &value, const TSLanguage *language) {
