--- src/s_conf.c.orig	2016-09-03 19:34:06 UTC
+++ src/s_conf.c
@@ -9841,7 +9841,7 @@ static void conf_download_complete(const
 	{
 		char *urlfile = url_getfilename(url);
 		char *file_basename = unreal_getfilename(urlfile);
-		char *tmp = unreal_mktemp("tmp", file_basename);
+		char *tmp = unreal_mktemp("/var/run/ircd/tmp", file);
 		free(urlfile);
 
 		if (cached)
