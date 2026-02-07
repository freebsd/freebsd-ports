--- thirdparty_unman/chmlib/src/chm_lib.c.orig
+++ thirdparty_unman/chmlib/src/chm_lib.c
@@ -740,10 +740,10 @@ static Int64 _chm_fetch_bytes(struct chmFile *h,
 #endif
 #else
 #ifdef CHM_USE_IO64
-    oldOs = lseek64(h->fd, 0, SEEK_CUR);
-    lseek64(h->fd, os, SEEK_SET);
+    oldOs = lseek(h->fd, 0, SEEK_CUR);
+    lseek(h->fd, os, SEEK_SET);
     readLen = read(h->fd, buf, len);
-    lseek64(h->fd, oldOs, SEEK_SET);
+    lseek(h->fd, oldOs, SEEK_SET);
 #else
     oldOs = lseek(h->fd, 0, SEEK_CUR);
     lseek(h->fd, (long)os, SEEK_SET);
