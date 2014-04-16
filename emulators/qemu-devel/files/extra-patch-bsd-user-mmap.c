--- a/bsd-user/mmap.c
+++ b/bsd-user/mmap.c
@@ -238,8 +238,13 @@ abi_ulong mmap_find_vma(abi_ulong start,
         for (addr1 = addr; addr1 < (addr + size); addr1 += TARGET_PAGE_SIZE) {
             prot |= page_get_flags(addr1);
         }
-        if (prot == 0)
-            break;
+        if (prot == 0) {
+            if (reserved_va && addr + size >= reserved_va) {
+                addr = 0;
+            } else {
+                break;
+            }
+        }
         addr += qemu_host_page_size;
         /* we found nothing */
         if (addr == addr_start)
