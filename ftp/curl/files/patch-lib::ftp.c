--- lib/ftp.c.orig	Tue May 13 23:31:00 2003
+++ lib/ftp.c	Sun Jun 15 18:57:27 2003
@@ -2055,7 +2055,7 @@
       struct tm buffer;
       tm = (struct tm *)localtime_r(&data->info.filetime, &buffer);
 #else
-      tm = localtime((unsigned long *)&data->info.filetime);
+      tm = localtime((time_t *)&data->info.filetime);
 #endif
       /* format: "Tue, 15 Nov 1994 12:45:26 GMT" */
       strftime(buf, BUFSIZE-1, "Last-Modified: %a, %d %b %Y %H:%M:%S GMT\r\n",
