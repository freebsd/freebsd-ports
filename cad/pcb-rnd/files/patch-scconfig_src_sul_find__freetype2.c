--- scconfig/src/sul/find_freetype2.c.orig	2022-05-27 13:11:01 UTC
+++ scconfig/src/sul/find_freetype2.c
@@ -57,7 +57,7 @@ int find_sul_freetype2(const char *name, int logdepth,
 	if (try_icl(logdepth, node, test_c, NULL, NULL, "-lfreetype"))
 		return 0;
 
-	if (try_icl(logdepth, node, test_c, NULL, "-I/usr/include/freetype2 -I/usr/include/freetype2/freetype", "-lfreetype"))
+	if (try_icl(logdepth, node, test_c, NULL, "-I%%LOCALBASE%%/include/freetype2 -I%%LOCALBASE%%/include/freetype2/freetype -L%%LOCALBASE%%/lib", "-lfreetype"))
 		return 0;
 
 	if (try_icl(logdepth, node, test_c, NULL, "-I/usr/include/freetype2", "-lfreetype"))
