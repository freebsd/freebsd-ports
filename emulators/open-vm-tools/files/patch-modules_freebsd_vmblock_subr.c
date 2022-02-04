--- modules/freebsd/vmblock/subr.c.orig	2022-02-04 12:59:09 UTC
+++ modules/freebsd/vmblock/subr.c
@@ -392,7 +392,13 @@ VMBlockNodeGet(struct mount *mp,        // IN: VMBlock
    }
 
    /* Before FreeBSD 7, insmntque was called by getnewvnode. */
-#if __FreeBSD_version >= 700055
+#if __FreeBSD_version >= 1400051
+   error = insmntque1(vp, mp);
+   if (error != 0) {
+      VMBlockInsMntQueDtr(vp, xp);
+      return error;
+   }
+#else
    error = insmntque1(vp, mp, VMBlockInsMntQueDtr, xp);
    if (error != 0) {
       return error;
