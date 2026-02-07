--- src/dcd/server/autocomplete/symbols.d	2022-11-14 15:33:36.047717000 -0500
+++ src/dcd/server/autocomplete/symbols.d	2022-11-14 15:40:15.800529000 -0500
@@ -18,6 +18,7 @@
 
 module dcd.server.autocomplete.symbols;
 
+import std.experimental.allocator;
 import std.experimental.logger;
 import std.typecons;
 
@@ -47,10 +48,10 @@
 {
 	AutocompleteResponse response;
 	RollbackAllocator rba;
-	auto allocator = scoped!(ASTAllocator)();
+	scope allocator = new ASTAllocator();
 	auto cache = StringCache(request.sourceCode.length.optimalBucketCount);
 	SymbolStuff stuff = getSymbolsForCompletion(request,
-		CompletionType.location, allocator, &rba, cache, moduleCache);
+		CompletionType.location, allocator.allocatorObject, &rba, cache, moduleCache);
 	scope(exit) stuff.destroy();
 	if (stuff.symbols.length > 0)
 	{
@@ -75,9 +76,9 @@
 	auto cache = StringCache(request.sourceCode.length.optimalBucketCount);
 	const(Token)[] tokenArray = getTokensForParser(cast(ubyte[]) request.sourceCode,
 		config, &cache);
-	auto allocator = scoped!(ASTAllocator)();
+	scope allocator = new ASTAllocator();
 	RollbackAllocator rba;
-	ScopeSymbolPair pair = generateAutocompleteTrees(tokenArray, allocator,
+	ScopeSymbolPair pair = generateAutocompleteTrees(tokenArray, allocator.allocatorObject,
 		&rba, request.cursorPosition, moduleCache);
 	scope(exit) pair.destroy();
 
