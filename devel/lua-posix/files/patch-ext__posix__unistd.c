--- ext/posix/unistd.c.orig	2015-03-01 18:26:42 UTC
+++ ext/posix/unistd.c
@@ -326,6 +326,7 @@ Pexecp(lua_State *L)
 }
 
 
+#if 0
 #if LPOSIX_2001_COMPLIANT
 
 #if !HAVE_DECL_FDATASYNC
@@ -350,6 +351,7 @@ Pfdatasync(lua_State *L)
   return pushresult(L, fdatasync(fd), NULL);
 }
 #endif
+#endif
 
 
 /***
@@ -1032,9 +1034,11 @@ static const luaL_Reg posix_unistd_fns[]
 	LPOSIX_FUNC( Pdup2		),
 	LPOSIX_FUNC( Pexec		),
 	LPOSIX_FUNC( Pexecp		),
+#if 0
 #if LPOSIX_2001_COMPLIANT
 	LPOSIX_FUNC( Pfdatasync		),
 #endif
+#endif
 	LPOSIX_FUNC( Pfork		),
 	LPOSIX_FUNC( Pfsync		),
 	LPOSIX_FUNC( Pgetcwd		),
