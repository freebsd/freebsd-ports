From nox Mon Sep 17 00:00:00 2001
From: Juergen Lock <nox@jelal.kn-bremen.de>
Date: 06 Apr 2014 02:20:00 +0200
Subject: Wrap bsd-user mmap(2) allocation search to low memory

Wrap bsd-user mmap(2) allocation search to low memory to avoid
another assert on 64bit hosts.

Signed-off-by: Juergen Lock <nox@jelal.kn-bremen.de>

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
