--- fat.c.orig	Wed May 30 16:16:49 2007
+++ fat.c	Wed May 30 16:17:12 2007
@@ -277,7 +277,7 @@ magic:
 
 	label = get_attr_volume_id(dir, root_dir_entries);
 
-	vs = (struct vfat_super_block *) volume_id_get_buffer(id, off, 0x200);
+	vs = (struct vfat_super_block *) volume_id_get_buffer(id, off, sector_size);
 	if (vs == NULL)
 		return -1;
 
@@ -294,7 +294,7 @@ magic:
 fat32:
 	/* FAT32 should have a valid signature in the fsinfo block */
 	fsinfo_sect = le16_to_cpu(vs->type.fat32.fsinfo_sector);
-	buf = volume_id_get_buffer(id, off + (fsinfo_sect * sector_size), 0x200);
+	buf = volume_id_get_buffer(id, off + (fsinfo_sect * sector_size), sector_size);
 	if (buf == NULL)
 		return -1;
 	fsinfo = (struct fat32_fsinfo *) buf;
@@ -303,7 +303,7 @@ fat32:
 	if (memcmp(fsinfo->signature2, "\x72\x72\x41\x61", 4) != 0)
 		err("Found invalid signature2: 0x%08x", fsinfo->signature2);
 
-	vs = (struct vfat_super_block *) volume_id_get_buffer(id, off, 0x200);
+	vs = (struct vfat_super_block *) volume_id_get_buffer(id, off, sector_size);
 	if (vs == NULL)
 		return -1;
 
@@ -355,7 +355,7 @@ fat32:
 	if (maxloop == 0)
 		dbg("reached maximum follow count of root cluster chain, give up");
 
-	vs = (struct vfat_super_block *) volume_id_get_buffer(id, off, 0x200);
+	vs = (struct vfat_super_block *) volume_id_get_buffer(id, off, sector_size);
 	if (vs == NULL)
 		return -1;
 
