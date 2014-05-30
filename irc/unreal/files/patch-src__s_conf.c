--- ./src/s_conf.c.orig	2013-11-24 20:24:26.000000000 +0100
+++ ./src/s_conf.c	2014-05-23 00:34:33.000000000 +0200
@@ -9832,7 +9832,7 @@
 	{
 		char *urlfile = url_getfilename(url);
 		char *file_basename = unreal_getfilename(urlfile);
-		char *tmp = unreal_mktemp("tmp", file_basename);
+		char *tmp = unreal_mktemp("%%RUNDIR%%/tmp", file);
 		free(urlfile);
 
 		if (cached)
