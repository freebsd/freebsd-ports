--- utils/glvis/glvis.cpp.orig	2022-12-31 03:37:54 UTC
+++ utils/glvis/glvis.cpp
@@ -158,7 +158,7 @@ void TConsoleGLVis::DisplayMapDone(int accepts, int to
 static void ShowUsage()
 {
 	fprintf(stderr, "\nGLVIS version 1.6, Copyright (c)2000-2006 Janis "
-		"Legzdinsh ("__DATE__" "__TIME__")\n");
+		"Legzdinsh (" __DATE__ " " __TIME__ ")\n");
 	fprintf(stderr, "Usage: glvis [options] file[.wad]\n");
 	fprintf(stderr, "    -s            silent mode\n");
 	fprintf(stderr, "    -f            fast mode\n");
