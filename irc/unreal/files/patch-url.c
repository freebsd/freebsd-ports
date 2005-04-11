--- src/url.c	Sat Jul  3 21:04:31 2004
+++ src/url.c	Mon Feb  7 04:31:06 2005
@@ -141,7 +141,7 @@
 	CURLcode res;
 	char *file = url_getfilename(url);
 	char *filename = unreal_getfilename(file);
-	char *tmp = unreal_mktemp("tmp", filename ? filename : "download.conf");
+	char *tmp = unreal_mktemp("%%RUNDIR%%/tmp", filename ? filename : "download.conf");
 	FILE *fd;
 
 
@@ -236,7 +236,7 @@
 	{
 		char *file = url_getfilename(url);
 		char *filename = unreal_getfilename(file);
-        	char *tmp = unreal_mktemp("tmp", filename ? filename : "download.conf");
+        	char *tmp = unreal_mktemp("%%RUNDIR%%/tmp", filename ? filename : "download.conf");
 		FileHandle *handle = malloc(sizeof(FileHandle));
 		handle->fd = fopen(tmp, "wb");
 		if (!handle->fd)
