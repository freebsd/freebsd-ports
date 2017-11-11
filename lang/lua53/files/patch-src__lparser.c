--- src/lparser.c.orig	2016-08-01 19:51:24 UTC
+++ src/lparser.c
@@ -1392,7 +1392,7 @@ static void test_then_block (LexState *ls, int *escape
     luaK_goiffalse(ls->fs, &v);  /* will jump to label if condition is true */
     enterblock(fs, &bl, 0);  /* must enter block before 'goto' */
     gotostat(ls, v.t);  /* handle goto/break */
-    skipnoopstat(ls);  /* skip other no-op statements */
+    while (testnext(ls, ';')) {}  /* skip semicolons */
     if (block_follow(ls, 0)) {  /* 'goto' is the entire block? */
       leaveblock(fs);
       return;  /* and that is it */
