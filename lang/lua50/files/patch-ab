--- src/lib/lmathlib.c.orig	Tue Mar 11 21:30:37 2003
+++ src/lib/lmathlib.c	Fri May  9 02:32:59 2003
@@ -170,7 +170,7 @@
 static int math_random (lua_State *L) {
   /* the `%' avoids the (rare) case of r==1, and is needed also because on
      some systems (SunOS!) `rand()' may return a value larger than RAND_MAX */
-  lua_Number r = (lua_Number)(rand()%RAND_MAX) / (lua_Number)RAND_MAX;
+  lua_Number r = (lua_Number)(random()%RAND_MAX) / (lua_Number)RAND_MAX;
   switch (lua_gettop(L)) {  /* check number of arguments */
     case 0: {  /* no arguments */
       lua_pushnumber(L, r);  /* Number between 0 and 1 */
@@ -196,7 +196,7 @@
 
 
 static int math_randomseed (lua_State *L) {
-  srand(luaL_checkint(L, 1));
+  srandom(luaL_checkint(L, 1));
   return 0;
 }
 
