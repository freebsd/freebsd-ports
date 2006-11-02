--- lposix.c.orig	Thu Nov  2 11:08:39 2006
+++ lposix.c	Thu Nov  2 11:11:29 2006
@@ -64,7 +64,7 @@
 	}
 	else
 	{
-		int j=luaL_findstring(luaL_checkstring(L, i), S);
+		int j=luaL_checkoption(L, i, NULL, S);
 		if (j==-1) luaL_argerror(L, i, "unknown selector");
 		return F(L, j, data);
 	}
