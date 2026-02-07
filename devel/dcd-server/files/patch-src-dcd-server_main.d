--- src/dcd/server/main.d	2022-11-14 15:42:33.385930000 -0500
+++ src/dcd/server/main.d	2022-11-14 15:43:15.544622000 -0500
@@ -24,8 +24,8 @@
 import std.conv;
 import std.datetime.stopwatch : AutoStart, StopWatch;
 import std.exception : enforce;
-import stdx.allocator;
-import stdx.allocator.mallocator;
+import std.experimental.allocator;
+import std.experimental.allocator.mallocator;
 import std.experimental.logger;
 import std.file;
 import std.getopt;
@@ -176,7 +176,7 @@
 		info("Sockets shut down.");
 	}
 
-	ModuleCache cache = ModuleCache(new ASTAllocator);
+	ModuleCache cache = ModuleCache(new ASTAllocator().allocatorObject);
 	cache.addImportPaths(importPaths);
 	infof("Import directories:\n    %-(%s\n    %)", cache.getImportPaths());
 
