--- src/common/filesystem.c.orig	2026-05-14 07:18:11 UTC
+++ src/common/filesystem.c
@@ -2226,7 +2226,8 @@ FS_BuildRawPath(void)
 	// binary compiled with SYSTEMWIDE (installed from
 	// packages), but no systemwide game data.
 #ifdef SYSTEMWIDE
-	FS_AddDirToRawPath(SYSTEMDIR, false, false);
+	FS_AddDirToRawPath(SYSTEMDATADIR, false, false);
+	FS_AddDirToRawPath(SYSTEMLIBDIR, false, false);
 #endif
 
 	// The CD must be the last directory of the path,
