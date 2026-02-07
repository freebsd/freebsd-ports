--- src/stlink-lib/flash_loader.c.orig	2025-04-02 12:20:17 UTC
+++ src/stlink-lib/flash_loader.c
@@ -788,7 +788,7 @@ int32_t stlink_flashloader_write(stlink_t *sl, flash_l
       if (stm32l1_write_half_pages(sl, fl, addr, base, len, pagesize)) {
         return (-1);
       } else {
-        off = (size_t)(len / pagesize) * pagesize;
+        off = (uint32_t)((size_t)(len / pagesize) * pagesize);
       }
     }
 
