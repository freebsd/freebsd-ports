As we unbundle lua, we cannot ensure that this version check succeeds.
Removal of the version check allows us to build a working binary, but
it is uncertain if there are any residual effects from the version
mismatch.

To rule out that possibility, the sandbox code is left disabled by
default but can be enabled if desired through the SANDBOX option.

--- src/nhlua.c.orig	2025-03-17 12:18:47 UTC
+++ src/nhlua.c
@@ -2236,6 +2236,7 @@ nhl_init(nhl_sandbox_info *sbi)
 lua_State *
 nhl_init(nhl_sandbox_info *sbi)
 {
+#if 0
     /* It would be nice to import EXPECTED from each build system. XXX */
     /* And it would be nice to do it only once, but it's cheap. */
 #ifndef NHL_VERSION_EXPECTED
@@ -2248,6 +2249,7 @@ nhl_init(nhl_sandbox_info *sbi)
             "sandbox doesn't know this Lua version: this=%d != expected=%d ",
             LUA_VERSION_RELEASE_NUM, NHL_VERSION_EXPECTED);
     }
+#endif
 #endif
 
     lua_State *L = nhlL_newstate(sbi, "nhl_init");
