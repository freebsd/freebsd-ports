--- filesel/filesystem-rpg.c.orig	2024-02-19 21:41:47 UTC
+++ filesel/filesystem-rpg.c
@@ -609,11 +609,11 @@ static int rpg_dir_readdir_iterate (ocpdirhandle_pt _s
 		self->dir->owner->archive_filehandle->seek_set (self->dir->owner->archive_filehandle, self->nextheader_offset);
 		if (self->dir->owner->archive_filehandle->read (self->dir->owner->archive_filehandle, header, sizeof (header)) < 6)
 		{
-finished:
 			const char *filename;
 			uint8_t *metadata = 0;
 			size_t metadatasize = 0;
 
+finished:
 			self->dir->owner->ready = 1;
 			rpg_instance_encode_blob (self->dir->owner, &metadata, &metadatasize);
 			if (metadata)
