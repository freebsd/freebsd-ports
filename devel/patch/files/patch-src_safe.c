--- src/safe.c.orig	2025-02-27 13:33:25 UTC
+++ src/safe.c
@@ -571,6 +571,8 @@ safe_xstat (char *pathname, struct stat *buf, int flag
   int dirfd = traverse_path (&pathname, false);
   if (dirfd == DIRFD_INVALID)
     return -1;
+  if (! strcmp (pathname, ""))
+    return EINVAL;
   return fstatat (dirfd, pathname, buf, flags);
 }
 
