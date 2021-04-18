--- src/import/Import.cpp.orig	2021-02-04 18:52:51 UTC
+++ src/import/Import.cpp
@@ -803,9 +803,11 @@ bool Importer::Import( AudacityProject &project,
 /* i18n-hint: %s will be the filename */
 "Audacity did not recognize the type of the file '%s'.\n\n%sFor uncompressed files, also try File > Import > Raw Data.")
          .Format( fName,
+#if defined(USE_FFMPEG)
                   !FFmpegLibsInst()
-                  ? XO("Try installing FFmpeg.\n\n")
-                  : XO("") );
+                  ? XO("Try installing FFmpeg.\n\n") :
+#endif
+		Verbatim("") );
    }
    else
    {
