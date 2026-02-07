--- src/hdd_file.c.orig	2020-12-01 19:49:05 UTC
+++ src/hdd_file.c
@@ -14,9 +14,9 @@ void hdd_load_ext(hdd_file_t *hdd, const char *fn, int
         {
 		/* Try to open existing hard disk image */
 		if (read_only)
-                        hdd->f = (void*)fopen64(fn, "rb");
+                        hdd->f = (void*)fopen(fn, "rb");
 		else
-                        hdd->f = (void*)fopen64(fn, "rb+");
+                        hdd->f = (void*)fopen(fn, "rb+");
                 if (hdd->f != NULL)
                 {
                         hdd->img_type = HDD_IMG_RAW;
@@ -59,7 +59,7 @@ void hdd_load_ext(hdd_file_t *hdd, const char *fn, int
                         {
 				/* Failed because it does not exist,
 				   so try to create new file */
-				hdd->f = (void*)fopen64(fn, "wb+");
+				hdd->f = (void*)fopen(fn, "wb+");
 				if (hdd->f == NULL)
                                 {
 					pclog("Cannot create file '%s': %s",
@@ -128,7 +128,7 @@ int hdd_read_sectors(hdd_file_t *hdd, int offset, int 
                         transfer_sectors = hdd->sectors - offset;
                 addr = (uint64_t)offset * 512;
 
-                fseeko64((FILE*)hdd->f, addr, SEEK_SET);
+                fseek((FILE*)hdd->f, addr, SEEK_SET);
                 fread(buffer, transfer_sectors*512, 1, (FILE*)hdd->f);
 
                 if (nr_sectors != transfer_sectors)
@@ -157,7 +157,7 @@ int hdd_write_sectors(hdd_file_t *hdd, int offset, int
                         transfer_sectors = hdd->sectors - offset;
                 addr = (uint64_t)offset * 512;
 
-                fseeko64((FILE*)hdd->f, addr, SEEK_SET);
+                fseek((FILE*)hdd->f, addr, SEEK_SET);
                 fwrite(buffer, transfer_sectors*512, 1, (FILE*)hdd->f);
 
                 if (nr_sectors != transfer_sectors)
@@ -189,7 +189,7 @@ int hdd_format_sectors(hdd_file_t *hdd, int offset, in
                 if ((hdd->sectors - offset) < transfer_sectors)
                         transfer_sectors = hdd->sectors - offset;
                 addr = (uint64_t)offset * 512;
-                fseeko64((FILE*)hdd->f, addr, SEEK_SET);
+                fseek((FILE*)hdd->f, addr, SEEK_SET);
                 for (c = 0; c < transfer_sectors; c++)
                         fwrite(zero_buffer, 512, 1, (FILE*)hdd->f);
 
