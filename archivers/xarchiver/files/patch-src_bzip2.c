--- src/bzip2.c.orig	2016-07-19 21:54:07 UTC
+++ src/bzip2.c
@@ -176,11 +176,11 @@ void xa_open_tar_compressed_file(XArchiv
 	if (archive->type == XARCHIVETYPE_TAR_BZ2)
 		command = g_strconcat(tar," tfjv ",archive->escaped_path,NULL);
 	else if (archive->type == XARCHIVETYPE_TAR_LZMA)
-		command = g_strconcat(tar," tv --use-compress-program=lzma -f ",archive->escaped_path,NULL);
+		command = g_strconcat(tar," tv --use-compress-program='lzma -d' -f ",archive->escaped_path,NULL);
 	else if (archive->type == XARCHIVETYPE_TAR_XZ)
-		command = g_strconcat(tar," tv --use-compress-program=xz -f ",archive->escaped_path,NULL);
+		command = g_strconcat(tar," tv --use-compress-program='xz -d' -f ",archive->escaped_path,NULL);
 	else if (archive->type == XARCHIVETYPE_TAR_LZOP)
-		command = g_strconcat(tar," tv --use-compress-program=lzop -f ",archive->escaped_path,NULL);
+		command = g_strconcat(tar," tv --use-compress-program='lzop -d' -f ",archive->escaped_path,NULL);
 	/* else fail? */
 
 	archive->has_properties = archive->can_add = archive->can_extract = archive->has_test = TRUE;
