--- src/url.c.orig	2016-09-03 19:34:06 UTC
+++ src/url.c
@@ -174,7 +174,7 @@ char *download_file(const char *url, cha
 	CURLcode res;
 	char *file = url_getfilename(url);
 	char *filename = unreal_getfilename(file);
-	char *tmp = unreal_mktemp("tmp", filename ? filename : "download.conf");
+	char *tmp = unreal_mktemp("/var/run/ircd/tmp", filename ? filename : "download.conf");
 	FILE *fd;
 
 
@@ -359,7 +359,7 @@ void download_file_async(const char *url
 	{
 		char *file = url_getfilename(url);
 		char *filename = unreal_getfilename(file);
-        	char *tmp = unreal_mktemp("tmp", filename ? filename : "download.conf");
+        	char *tmp = unreal_mktemp("/var/run/ircd/tmp", filename ? filename : "download.conf");
 		FileHandle *handle = MyMallocEx(sizeof(FileHandle));
 		handle->fd = fopen(tmp, "wb");
 		if (!handle->fd)
