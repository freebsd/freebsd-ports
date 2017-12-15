--- src/ldebug.c.orig	2016-10-19 12:32:10 UTC
+++ src/ldebug.c
@@ -653,6 +653,7 @@ l_noret luaG_runerror (lua_State *L, const char *fmt, 
   CallInfo *ci = L->ci;
   const char *msg;
   va_list argp;
+  luaC_checkGC(L);  /* error message uses memory */
   va_start(argp, fmt);
   msg = luaO_pushvfstring(L, fmt, argp);  /* format message */
   va_end(argp);
