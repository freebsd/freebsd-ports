--- src/lib/oogl/refcomm/streampool.h	2006/07/14 17:47:21	1.4
+++ src/lib/oogl/refcomm/streampool.h	2006/07/15 19:06:00	1.5
@@ -116,7 +116,7 @@
 extern IOBFILE *PoolInputFile(Pool *);
 extern FILE *PoolOutputFile(Pool *);
 extern void  PoolDoReread(Pool *);
-extern void PoolClose(register Pool *p);
+extern void PoolClose(Pool *p);
 extern int   PoolOType(Pool *, int otype);
 extern void  PoolSetOType(Pool *, int otype);
 extern Pool *PoolByName(char *name);
