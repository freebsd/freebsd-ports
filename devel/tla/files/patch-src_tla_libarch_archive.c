--- src/tla/libarch/archive.c.orig	2006-07-20 06:34:40 UTC
+++ src/tla/libarch/archive.c
@@ -1114,7 +1114,8 @@ invoke_tar_extract (int * pid_ret)
 
       *(t_uchar **)ar_push ((void **)&argv, 0, sizeof (char *)) = cfg__gnu_tar;
       *(t_uchar **)ar_push ((void **)&argv, 0, sizeof (char *)) = "-m";
-      *(t_uchar **)ar_push ((void **)&argv, 0, sizeof (char *)) = "--preserve";
+      *(t_uchar **)ar_push ((void **)&argv, 0, sizeof (char *)) = "-p";
+      *(t_uchar **)ar_push ((void **)&argv, 0, sizeof (char *)) = "-s";
       *(t_uchar **)ar_push ((void **)&argv, 0, sizeof (char *)) = "-zxf";
       *(t_uchar **)ar_push ((void **)&argv, 0, sizeof (char *)) = "-";
       *(t_uchar **)ar_push ((void **)&argv, 0, sizeof (char *)) = 0;
