--- ext/posix/posix.c.orig	2013-09-09 07:15:14 UTC
+++ ext/posix/posix.c
@@ -68,6 +68,10 @@
 #include "lauxlib.h"
 #include "lua52compat.h"
 
+#if defined __FreeBSD__ || defined __DragonFly__
+#define	O_DSYNC	O_SYNC
+#endif
+
 #ifndef STREQ
 #  define STREQ(a, b)     (strcmp (a, b) == 0)
 #endif
@@ -3697,6 +3701,7 @@ static int Pfsync(lua_State *L)
   return pushresult(L, fsync(fd), NULL);
 }
 
+#if 0
 #if _POSIX_VERSION >= 200112L
 /***
  synchronize a file's in-core state with storage device without metadata
@@ -3712,6 +3717,7 @@ static int Pfdatasync(lua_State *L)
   return pushresult(L, fdatasync(fd), NULL);
 }
 #endif
+#endif
 
 /***
 reposition read/write file offset
@@ -3771,9 +3777,11 @@ static const luaL_Reg R[] =
 	MENTRY( Perrno		),
 	MENTRY( Pexec		),
 	MENTRY( Pexecp		),
+#if 0
 #if _POSIX_VERSION >= 200112L
 	MENTRY( Pfdatasync	),
 #endif
+#endif
 	MENTRY( Pfcntl		),
 	MENTRY( Pfileno		),
 	MENTRY( Pfiles		),
