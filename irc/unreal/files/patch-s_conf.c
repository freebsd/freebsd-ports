--- src/s_conf.c	Mon Mar 21 09:10:42 2005
+++ src/s_conf.c	Mon Mar 21 09:15:09 2005
@@ -8609,7 +8609,7 @@
 		{
 			char *urlfile = url_getfilename(url);
 			char *file = unreal_getfilename(urlfile);
-			char *tmp = unreal_mktemp("tmp", file);
+			char *tmp = unreal_mktemp("%%RUNDIR%%/tmp", file);
 			unreal_copyfileex(inc->file, tmp, 1);
 			add_remote_include(tmp, url, 0, NULL);
 			free(urlfile);
