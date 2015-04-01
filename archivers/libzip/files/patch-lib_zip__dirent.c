CVE-2015-2331: ZIP Integer Overflow
Upstream commit: http://hg.nih.at/libzip/rev/9f11d54f692e

--- lib/zip_dirent.c.orig	2013-11-28 16:57:10 UTC
+++ lib/zip_dirent.c
@@ -110,7 +110,7 @@ _zip_cdir_new(zip_uint64_t nentry, struc
 
     if (nentry == 0)
 	cd->entry = NULL;
-    else if ((cd->entry=(struct zip_entry *)malloc(sizeof(*(cd->entry))*(size_t)nentry)) == NULL) {
+    else if ((nentry > SIZE_MAX/sizeof(*(cd->entry))) || (cd->entry=(struct zip_entry *)malloc(sizeof(*(cd->entry))*(size_t)nentry)) == NULL) {
 	_zip_error_set(error, ZIP_ER_MEMORY, 0);
 	free(cd);
 	return NULL;
