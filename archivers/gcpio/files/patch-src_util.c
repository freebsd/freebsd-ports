https://git.savannah.gnu.org/cgit/cpio.git/commit/?id=df55fb19be545e22d023950263ed5d0756edf81e

--- src/util.c.orig	2019-11-03 15:07:23 UTC
+++ src/util.c
@@ -1140,8 +1140,16 @@ stat_to_cpio (struct cpio_file_stat *hdr, struct stat 
   hdr->c_nlink = st->st_nlink;
   hdr->c_uid = CPIO_UID (st->st_uid);
   hdr->c_gid = CPIO_GID (st->st_gid);
-  hdr->c_rdev_maj = major (st->st_rdev);
-  hdr->c_rdev_min = minor (st->st_rdev);
+  if (S_ISBLK (st->st_mode) || S_ISCHR (st->st_mode))
+    {
+      hdr->c_rdev_maj = major (st->st_rdev);
+      hdr->c_rdev_min = minor (st->st_rdev);
+    }
+  else
+    {
+      hdr->c_rdev_maj = 0;
+      hdr->c_rdev_min = 0;
+    }
   hdr->c_mtime = st->st_mtime;
   hdr->c_filesize = st->st_size;
   hdr->c_chksum = 0;
