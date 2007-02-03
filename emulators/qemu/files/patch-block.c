Index: qemu/block.c
@@ -381,7 +381,7 @@
     else
         open_flags = flags & ~(BDRV_O_FILE | BDRV_O_SNAPSHOT);
     ret = drv->bdrv_open(bs, filename, open_flags);
-    if (ret == -EACCES && !(flags & BDRV_O_FILE)) {
+    if ((ret == -EACCES || ret == -EPERM) && !(flags & BDRV_O_FILE)) {
         ret = drv->bdrv_open(bs, filename, BDRV_O_RDONLY);
         bs->read_only = 1;
     }
