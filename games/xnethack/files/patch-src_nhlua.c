As we unbundle lua, we cannot ensure that this version check succeeds.
Removal of the version check allows us to build a working binary, but
it is uncertain if there are any residual effects from the version
mismatch.

To rule out that possibility, the sandbox code is left disabled by
default but can be enabled if desired through the SANDBOX option.

--- src/nhlua.c.orig	2022-06-25 04:31:43 UTC
+++ src/nhlua.c
@@ -1652,20 +1652,6 @@ DISABLE_WARNING_CONDEXPR_IS_CONSTANT
 lua_State *
 nhl_init(nhl_sandbox_info *sbi)
 {
-	/* It would be nice to import EXPECTED from each build system. XXX */
-	/* And it would be nice to do it only once, but it's cheap. */
-#ifndef NHL_VERSION_EXPECTED
-#define NHL_VERSION_EXPECTED 50404
-#endif
-
-#ifdef NHL_SANDBOX
-    if(NHL_VERSION_EXPECTED != LUA_VERSION_RELEASE_NUM){
-	panic(
-	    "sandbox doesn't know this Lua version: this=%d != expected=%d ",
-	    LUA_VERSION_RELEASE_NUM, NHL_VERSION_EXPECTED);
-    }
-#endif
-
     lua_State *L = nhlL_newstate(sbi);
 
     iflags.in_lua = TRUE;
@@ -2348,7 +2334,7 @@ nhlL_newstate (nhl_sandbox_info *sbi) {
     }
 
     lua_State *L = lua_newstate(nhl_alloc, nud);
-#if LUA_VERSION_NUM == 503
+#ifndef luai_likely
 # define luai_likely(x) (x)
 #endif
     if (luai_likely(L)) {
