--- src/wadgen/Files.c.orig	2026-10-15 11:58:04 UTC
+++ src/wadgen/Files.c
@@ -95,7 +95,7 @@ bool File_Prepare(wgenfile_t *wgenfile, const char *fi
     ZeroMemory(wgenfile->fileName, MAX_PATH);
     ZeroMemory(wgenfile->basePath, MAX_PATH);
 
-    sprintf(wgenfile->basePath, "%s", File_GetExePath());
+    strcpy(wgenfile->basePath, ".");
 
     memcpy(wgenfile->filePath, filename, strlen(filename));
     memcpy(wgenfile->fileNoExt, wgenfile->filePath, MAX_PATH);
