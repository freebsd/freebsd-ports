--- src/msqld/main/compare.c.old	Fri Jul 30 00:14:10 2004
+++ src/msqld/main/compare.c	Fri Jul 30 00:15:37 2004
@@ -1150,7 +1150,7 @@
 			if (curCond->op == BETWEEN_OP)
 			{
 				tmp = processBetweenMatch(cacheEntry,
-					curCond, data, offset, tmpVal);
+					curCond, data, offset, &tmpVal);
 			}
 			else
 			{
