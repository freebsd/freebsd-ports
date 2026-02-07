--- src/common/filesystem.c.orig	2022-01-22 08:51:28 UTC
+++ src/common/filesystem.c
@@ -2029,7 +2029,8 @@ void FS_BuildRawPath(void) {
 	// binary compiled with SYSTEMWIDE (installed from
 	// packages), but no systemwide game data.
 #ifdef SYSTEMWIDE
-	FS_AddDirToRawPath(SYSTEMDIR, false, false);
+	FS_AddDirToRawPath(SYSTEMDATADIR, false, false);
+	FS_AddDirToRawPath(SYSTEMLIBDIR, false, false);
 #endif
 
 	// The CD must be the last directory of the path,
