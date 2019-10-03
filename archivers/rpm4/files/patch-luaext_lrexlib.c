--- luaext/lrexlib.c.orig	2019-06-26 14:17:31 UTC
+++ luaext/lrexlib.c
@@ -11,7 +11,6 @@
 #include "lauxlib.h"
 #include "lrexlib.h"
 
-
 /* Sanity check */
 #if !defined(WITH_POSIX) && !defined(WITH_PCRE)
 #error Define WITH_POSIX or WITH_PCRE, otherwise this library is useless!
@@ -32,7 +31,7 @@ static int rex_comp(lua_State *L)
   regex_t *pr = (regex_t *)lua_newuserdata(L, sizeof(regex_t));
   pattern = luaL_checklstring(L, 1, &l);
 #ifdef REG_BASIC
-  pr->re_endp = pattern + lua_strlen(L, 1);
+  pr->re_endp = pattern + lua_rawlen(L, (1));
   res = regcomp(pr, pattern, REG_EXTENDED | REG_PEND);
 #else
   res = regcomp(pr, pattern, REG_EXTENDED);
