--- storage/myisam/mi_dynrec.cc.orig	2024-04-10 06:26:28 UTC
+++ storage/myisam/mi_dynrec.cc
@@ -86,17 +86,12 @@ bool mi_dynmap_file(MI_INFO *info, my_off_t size) {
     return true;
   }
   /*
-    I wonder if it is good to use MAP_NORESERVE. From the Linux man page:
-    MAP_NORESERVE
-      Do not reserve swap space for this mapping. When swap space is
-      reserved, one has the guarantee that it is possible to modify the
-      mapping. When swap space is not reserved one might get SIGSEGV
-      upon a write if no physical memory is available.
+    MAP_NORESERVE is unimplemented in FreeBSD
   */
   info->s->file_map = (uchar *)my_mmap(
       nullptr, (size_t)size,
       info->s->mode == O_RDONLY ? PROT_READ : PROT_READ | PROT_WRITE,
-      MAP_SHARED | MAP_NORESERVE, info->dfile, 0L);
+      MAP_SHARED, info->dfile, 0L);
   if (info->s->file_map == (uchar *)MAP_FAILED) {
     info->s->file_map = nullptr;
     return true;
