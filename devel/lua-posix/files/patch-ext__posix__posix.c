--- ./ext/posix/posix.c.orig	2013-09-09 09:15:14.000000000 +0200
+++ ./ext/posix/posix.c	2014-01-17 18:05:10.399556496 +0100
@@ -68,6 +68,10 @@
 #include "lauxlib.h"
 #include "lua52compat.h"
 
+#ifdef __FreeBSD__
+#define	O_DSYNC	O_SYNC
+#endif
+
 #ifndef STREQ
 #  define STREQ(a, b)     (strcmp (a, b) == 0)
 #endif
@@ -3697,6 +3701,7 @@
   return pushresult(L, fsync(fd), NULL);
 }
 
+#if 0
 #if _POSIX_VERSION >= 200112L
 /***
  synchronize a file's in-core state with storage device without metadata
@@ -3712,6 +3717,7 @@
   return pushresult(L, fdatasync(fd), NULL);
 }
 #endif
+#endif
 
 /***
 reposition read/write file offset
@@ -3771,9 +3777,11 @@
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
