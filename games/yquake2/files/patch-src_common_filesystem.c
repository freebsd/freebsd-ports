--- src/common/filesystem.c.orig	2025-09-14 05:35:31 UTC
+++ src/common/filesystem.c
@@ -2131,7 +2131,8 @@ FS_BuildRawPath(void)
 	// binary compiled with SYSTEMWIDE (installed from
 	// packages), but no systemwide game data.
 #ifdef SYSTEMWIDE
-	FS_AddDirToRawPath(SYSTEMDIR, false, false);
+	FS_AddDirToRawPath(SYSTEMDATADIR, false, false);
+	FS_AddDirToRawPath(SYSTEMLIBDIR, false, false);
 #endif
 
 	// The CD must be the last directory of the path,
