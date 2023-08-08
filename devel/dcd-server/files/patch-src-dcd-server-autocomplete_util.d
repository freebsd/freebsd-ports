--- src/dcd/server/autocomplete/util.d	2022-11-14 15:41:09.361709000 -0500
+++ src/dcd/server/autocomplete/util.d	2022-11-14 15:41:43.480412000 -0500
@@ -19,7 +19,7 @@
 module dcd.server.autocomplete.util;
 
 import std.algorithm;
-import stdx.allocator;
+import std.experimental.allocator;
 import std.experimental.logger;
 import std.range;
 import std.string;
@@ -134,7 +134,7 @@
  *     the request's source code, cursor position, and completion type.
  */
 SymbolStuff getSymbolsForCompletion(const AutocompleteRequest request,
-	const CompletionType type, IAllocator allocator, RollbackAllocator* rba,
+	const CompletionType type, RCIAllocator allocator, RollbackAllocator* rba,
 	ref StringCache cache, ref ModuleCache moduleCache)
 {
 	const(Token)[] tokenArray;
