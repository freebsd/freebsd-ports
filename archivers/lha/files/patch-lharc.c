--- src/lharc.c.orig	2000-10-05 17:33:34 UTC
+++ src/lharc.c
@@ -894,6 +894,7 @@ free_files(filec, filev)
 /*																			*/
 /* ------------------------------------------------------------------------ */
 /* Build temporary file name and store to TEMPORARY_NAME */
+#if !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
 void
 build_temporary_name()
 {
@@ -925,7 +926,7 @@ build_temporary_name()
 #endif
 #endif
 }
-
+#endif
 /* ------------------------------------------------------------------------ */
 static void
 modify_filename_extention(buffer, ext)
@@ -1038,7 +1039,7 @@ open_old_archive()
 		else
 			return NULL;
 	}
-	if (p = (char *) rindex(archive_name, '.')) {
+	if ((p = (char *) rindex(archive_name, '.'))) {
 		if (strucmp(".LZH", p) == 0
 		    || strucmp(".LZS", p) == 0
 		    || strucmp(".COM", p) == 0	/* DOS SFX */
