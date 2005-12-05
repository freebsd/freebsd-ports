--- fam/mntent_compat.c++.orig	Sun Dec  4 22:43:02 2005
+++ fam/mntent_compat.c++	Sun Dec  4 22:43:49 2005
@@ -98,7 +98,9 @@ flags2opts (int flags)
         if (flags & MNT_SYNCHRONOUS)    res = catopt(res, "sync");
         if (flags & MNT_NOEXEC)         res = catopt(res, "noexec");
         if (flags & MNT_NOSUID)         res = catopt(res, "nosuid");
+#ifdef MNT_NODEV
         if (flags & MNT_NODEV)          res = catopt(res, "nodev");
+#endif
         if (flags & MNT_UNION)          res = catopt(res, "union");
         if (flags & MNT_ASYNC)          res = catopt(res, "async");
         if (flags & MNT_NOATIME)        res = catopt(res, "noatime");
