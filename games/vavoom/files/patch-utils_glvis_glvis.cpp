--- utils/glvis/glvis.cpp.orig	2010-12-23 20:47:55.000000000 +0100
+++ utils/glvis/glvis.cpp	2018-03-15 03:06:38.264012000 +0100
@@ -158,7 +158,7 @@
 static void ShowUsage()
 {
 	fprintf(stderr, "\nGLVIS version 1.6, Copyright (c)2000-2006 Janis "
-		"Legzdinsh ("__DATE__" "__TIME__")\n");
+		"Legzdinsh (" __DATE__ " " __TIME__ ")\n");
 	fprintf(stderr, "Usage: glvis [options] file[.wad]\n");
 	fprintf(stderr, "    -s            silent mode\n");
 	fprintf(stderr, "    -f            fast mode\n");
