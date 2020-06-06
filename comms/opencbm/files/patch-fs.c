--- opencbm/libimgcopy/fs.c.orig	2017-09-06 16:59:00 UTC
+++ opencbm/libimgcopy/fs.c
@@ -121,7 +121,7 @@ static int open_disk(CBM_FILE fd, imgcopy_settings *se
         }
         else
         {
-            printf("filesize=%d, blockcount=%d, calc1=%d, calc2=%d\n", filesize, block_count, block_count * (BLOCKSIZE), block_count * (BLOCKSIZE + 1));
+            printf("filesize=%ld, blockcount=%d, calc1=%d, calc2=%d\n", (long)filesize, block_count, block_count * (BLOCKSIZE), block_count * (BLOCKSIZE + 1));
             /*   D64 sonderformate
 
                  for( tr = D82_TRACKS; !is_image && tr <= D82_TRACKS; )
