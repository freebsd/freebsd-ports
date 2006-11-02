--- posix.lua.orig	Thu Nov  2 12:52:39 2006
+++ posix.lua	Thu Nov  2 11:06:46 2006
@@ -4,7 +4,7 @@
 
 local function so(x)
 	local SOPATH= os.getenv"LUA_SOPATH" or "./"
-	assert(loadlib(SOPATH.."l"..x..".so","luaopen_"..x))()
+	assert(package.loadlib(SOPATH.."l"..x..".so","luaopen_"..x))()
 end
 
 so"posix"
