As we unbundle lua, we cannot ensure that this version check succeeds.
Removal of the version check allows us to build a working binary, but
it is uncertain if there are any residual effects from the version
mismatch.

To rule out that possibility, the sandbox code is left disabled by
default but can be enabled if desired through the SANDBOX option.

--- src/nhlua.c.orig	2023-05-16 21:33:58 UTC
+++ src/nhlua.c
@@ -2074,20 +2074,6 @@ DISABLE_WARNING_CONDEXPR_IS_CONSTANT
 lua_State *
 nhl_init(nhl_sandbox_info *sbi)
 {
-    /* It would be nice to import EXPECTED from each build system. XXX */
-    /* And it would be nice to do it only once, but it's cheap. */
-#ifndef NHL_VERSION_EXPECTED
-#define NHL_VERSION_EXPECTED 50404
-#endif
-
-#ifdef NHL_SANDBOX
-    if (NHL_VERSION_EXPECTED != LUA_VERSION_RELEASE_NUM) {
-        panic(
-             "sandbox doesn't know this Lua version: this=%d != expected=%d ",
-              LUA_VERSION_RELEASE_NUM, NHL_VERSION_EXPECTED);
-    }
-#endif
-
     lua_State *L = nhlL_newstate(sbi);
 
     iflags.in_lua = TRUE;
