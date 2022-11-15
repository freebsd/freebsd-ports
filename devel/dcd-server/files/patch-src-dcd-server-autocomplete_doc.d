--- src/dcd/server/autocomplete/doc.d	2022-11-14 15:33:18.687809000 -0500
+++ src/dcd/server/autocomplete/doc.d	2022-11-14 15:36:55.838929000 -0500
@@ -20,6 +20,7 @@
 
 import std.algorithm;
 import std.array;
+import std.experimental.allocator;
 import std.experimental.logger;
 import std.typecons;
 
@@ -45,10 +46,10 @@
 //	trace("Getting doc comments");
 	AutocompleteResponse response;
 	RollbackAllocator rba;
-	auto allocator = scoped!(ASTAllocator)();
+	scope allocator = new ASTAllocator();
 	auto cache = StringCache(request.sourceCode.length.optimalBucketCount);
 	SymbolStuff stuff = getSymbolsForCompletion(request, CompletionType.ddoc,
-		allocator, &rba, cache, moduleCache);
+		allocator.allocatorObject, &rba, cache, moduleCache);
 	if (stuff.symbols.length == 0)
 		warning("Could not find symbol");
 	else
