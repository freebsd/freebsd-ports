--- zzip/mmapped.c.orig	2021-01-04 23:05:08 UTC
+++ zzip/mmapped.c
@@ -661,7 +661,7 @@ zzip_disk_entry_fopen(ZZIP_DISK * disk, ZZIP_DISK_ENTR
 
     ___ /* a ZIP64 extended block may follow. */
     size_t csize = zzip_file_header_csize(header);
-    off_t offset = zzip_file_header_to_data(header);
+    size_t offset = zzip_file_header_sizeto_end(header);
     if (csize == 0xFFFFu) {
         struct zzip_extra_zip64* zip64 =
            zzip_file_header_to_extras(header);
@@ -682,7 +682,7 @@ zzip_disk_entry_fopen(ZZIP_DISK * disk, ZZIP_DISK_ENTR
     file->zlib.zalloc = Z_NULL;
     file->zlib.zfree = Z_NULL;
     file->zlib.avail_in = csize;
-    file->zlib.next_in = offset;
+    file->zlib.next_in = (Bytef *)header + offset;
     ____;
 
     DBG2("compressed size %i", (int) file->zlib.avail_in);
