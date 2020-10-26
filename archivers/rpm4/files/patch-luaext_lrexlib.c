--- luaext/lrexlib.c.orig	2020-10-25 13:43:26 UTC
+++ luaext/lrexlib.c
@@ -32,7 +32,7 @@ static int rex_comp(lua_State *L)
   regex_t *pr = (regex_t *)lua_newuserdata(L, sizeof(regex_t));
   pattern = luaL_checklstring(L, 1, &l);
 #ifdef REG_BASIC
-  pr->re_endp = pattern + lua_strlen(L, 1);
+  pr->re_endp = pattern + lua_rawlen(L, (1));
   res = regcomp(pr, pattern, REG_EXTENDED | REG_PEND);
 #else
   res = regcomp(pr, pattern, REG_EXTENDED);
