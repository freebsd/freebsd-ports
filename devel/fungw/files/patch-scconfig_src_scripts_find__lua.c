--- scconfig/src/scripts/find_lua.c.orig	2022-05-06 14:29:08 UTC
+++ scconfig/src/scripts/find_lua.c
@@ -48,7 +48,7 @@ int find_script_lua(const char *name, int logdepth, in
 
 	/* Look at some standard places */
 	/* TODO: do we need -ldl? */
-	if (try_icl(logdepth, "libs/script/lua", test_c, NULL, NULL, "-llua -llualib -lm")) return 0;
+	if (try_icl(logdepth, "libs/script/lua", test_c, NULL, "-I%%LUA_INCDIR%%", "-L%%LUA_LIBDIR%% -llua-%%LUA_VER%%")) return 0;
 
 	/* lualib doesn't exist in lua 5.1.1 */
 	if (try_icl(logdepth, "libs/script/lua", test_c, NULL, NULL, "-llua -lm")) return 0;
