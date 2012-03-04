--- src/base/os.lua.orig	2012-01-31 15:40:25.000000000 +0200
+++ src/base/os.lua	2012-01-31 15:42:16.000000000 +0200
@@ -33,14 +33,6 @@
 			else
 				formats = { "lib%s.so", "%s.so" }
 				path = os.getenv("LD_LIBRARY_PATH") or ""
-	
-				io.input("/etc/ld.so.conf")
-				if io.input() then
-					for line in io.lines() do
-						path = path .. ":" .. line
-					end
-					io.input():close()
-				end
 			end
 			
 			table.insert(formats, "%s")	
