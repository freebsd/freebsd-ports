--- src/dcd/server/autocomplete/localuse.d	2022-11-14 15:33:24.333812000 -0500
+++ src/dcd/server/autocomplete/localuse.d	2022-11-14 15:38:33.174285000 -0500
@@ -18,6 +18,7 @@
 
 module dcd.server.autocomplete.localuse;
 
+import std.experimental.allocator;
 import std.experimental.logger;
 import std.range;
 import std.typecons;
@@ -45,7 +46,7 @@
 {
 	AutocompleteResponse response;
 	RollbackAllocator rba;
-	auto allocator = scoped!(ASTAllocator)();
+	scope allocator = new ASTAllocator();
 	auto cache = StringCache(request.sourceCode.length.optimalBucketCount);
 
 	// patchs the original request for the subsequent requests
@@ -60,7 +61,7 @@
 	{
 		auto sortedTokens = assumeSorted(tokenArray);
 		auto beforeTokens = sortedTokens.lowerBound(cursorPosition);
-		ScopeSymbolPair pair = generateAutocompleteTrees(tokenArray, allocator,
+		ScopeSymbolPair pair = generateAutocompleteTrees(tokenArray, allocator.allocatorObject,
 			&rba, request.cursorPosition, moduleCache);
 		auto expression = getExpression(beforeTokens);
 		return SymbolStuff(getSymbolsByTokenChain(pair.scope_, expression,
