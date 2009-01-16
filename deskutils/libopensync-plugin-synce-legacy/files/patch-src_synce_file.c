--- src/synce_file.c.orig	2007-03-27 22:14:24.000000000 +1000
+++ src/synce_file.c	2008-12-27 23:47:34.000000000 +0900
@@ -114,7 +114,7 @@
                   size = CeGetFileSize(h, NULL);
                   CeCloseHandle(h);
                 } else size = 0;
-                hash = g_strdup_printf("%ld-%u", ff->last_mod, size);
+                hash = g_strdup_printf("%ld-%u", (long)ff->last_mod, size);
 		osync_change_set_hash(change, hash);
                 fprintf(stderr, "%s(%s) hash %s\n", __func__, path, hash);
                 g_free(hash);
@@ -220,7 +220,8 @@
 	fileFormat	*ff;
 	WCHAR		*wfn;
 	DWORD		wr, e, opt;
-        char		*p, *s, *fn, *lfn, *str;
+        char		*p, *fn, *lfn, *str;
+	const char *s;
 	OSyncChangeType	ct;
 
 	osync_debug("SYNCE-SYNC", 4, "start: %s", __func__);	
@@ -495,7 +496,7 @@
                 if (r == 0) {
                         /* Error */
                         DWORD	e = CeGetLastError();
-                        char	*s = synce_strerror(e);
+                        const char	*s = synce_strerror(e);
                         osync_context_report_error(ctx, 1, "Error from CeReadFile (%d:%s)",
                                                    e, s);
                         CeCloseHandle(h);
@@ -672,7 +673,7 @@
 					&cnt, &find_data) == 0) {
 				/* FIX ME what does failure mean here ? */
 				e = CeGetLastError();
-				s = synce_strerror(e);
+				s = (char*)synce_strerror(e);
 				fprintf(stderr,
 					"CeFindAllFiles(%s) : %s",
 					lfn, s);
@@ -686,7 +687,7 @@
 				fprintf(stderr, "Yow create(%s)\n", lfn);
 				if (CeCreateDirectory(w, NULL) == 0) {
 					e = CeGetLastError();
-					s = synce_strerror(e);
+					s = (char*)synce_strerror(e);
 					fprintf(stderr,
 						"CeCreateDirectory(%s) : %s",
 						lfn, s);
@@ -707,7 +708,7 @@
 			CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0);
 	if (h == 0) {
 		e = CeGetLastError();
-		s = synce_strerror(e);
+		s = (char*)synce_strerror(e);
 		fprintf(stderr, "CeCreateFile(%s) : %s", lfn, s);
 		free(lfn);
 		return FALSE;
@@ -719,7 +720,7 @@
 	DWORD wr;
 	if (CeWriteFile(h, "Yow", 3, &wr, NULL) == 0) {
 		e = CeGetLastError();
-		s = synce_strerror(e);
+		s = (char*)synce_strerror(e);
 		fprintf(stderr, "CeWriteFile(%s) : %s", lfn, s);
 		free(lfn);
 		return FALSE;
