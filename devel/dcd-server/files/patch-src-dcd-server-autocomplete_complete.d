--- src/dcd/server/autocomplete/complete.d	2022-11-14 15:33:10.423557000 -0500
+++ src/dcd/server/autocomplete/complete.d	2022-11-14 15:35:18.150747000 -0500
@@ -21,6 +21,7 @@
 import std.algorithm;
 import std.array;
 import std.conv;
+import std.experimental.allocator;
 import std.experimental.logger;
 import std.file;
 import std.path;
@@ -213,9 +214,9 @@
 	mixin(TYPE_IDENT_CASES);
 	case tok!")":
 	case tok!"]":
-		auto allocator = scoped!(ASTAllocator)();
+		scope allocator = new ASTAllocator();
 		RollbackAllocator rba;
-		ScopeSymbolPair pair = generateAutocompleteTrees(tokenArray, allocator,
+		ScopeSymbolPair pair = generateAutocompleteTrees(tokenArray, allocator.allocatorObject,
 			&rba, cursorPosition, moduleCache);
 		scope(exit) pair.destroy();
 		response.setCompletions(pair.scope_, getExpression(beforeTokens),
@@ -229,9 +230,9 @@
 	case tok!";":
 	case tok!"}":
 	case tok!",":
-		auto allocator = scoped!(ASTAllocator)();
+		scope allocator = new ASTAllocator();
 		RollbackAllocator rba;
-		ScopeSymbolPair pair = generateAutocompleteTrees(tokenArray, allocator,
+		ScopeSymbolPair pair = generateAutocompleteTrees(tokenArray, allocator.allocatorObject,
 			&rba, 1, moduleCache);
 		scope(exit) pair.destroy();
 		response.setCompletions(pair.scope_, getExpression(beforeTokens),
@@ -302,9 +303,9 @@
 	case tok!")":
 	case tok!"]":
 	mixin(STRING_LITERAL_CASES);
-		auto allocator = scoped!(ASTAllocator)();
+		scope allocator = new ASTAllocator();
 		RollbackAllocator rba;
-		ScopeSymbolPair pair = generateAutocompleteTrees(tokenArray, allocator,
+		ScopeSymbolPair pair = generateAutocompleteTrees(tokenArray, allocator.allocatorObject,
 			&rba, cursorPosition, moduleCache);
 		scope(exit) pair.destroy();
 		auto expression = getExpression(beforeTokens[0 .. $ - 1]);
