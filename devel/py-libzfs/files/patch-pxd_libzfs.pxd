--- pxd/libzfs.pxd.orig	2017-05-30 15:07:35 UTC
+++ pxd/libzfs.pxd
@@ -34,7 +34,7 @@ IF FREEBSD_VERSION >= 1000000:
         enum lzc_send_flags:
             LZC_SEND_FLAG_EMBED_DATA
 
-        extern int lzc_send_space(const char *, const char *, uint64_t *)
+        extern int lzc_send_space(const char *, const char *, enum, uint64_t *)
         extern int lzc_bookmark(nvpair.nvlist_t *bookmarks, nvpair.nvlist_t **errlist)
 
 
