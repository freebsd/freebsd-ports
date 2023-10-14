--- libs/wine/config.c.orig	2023-07-17 16:05:30.000000000 +0300
+++ libs/wine/config.c	2023-09-10 09:32:37.552268000 +0300
@@ -147,7 +147,7 @@ static char *get_runtime_exedir(void)
     static int pathname[] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
     size_t dir_size = PATH_MAX;
     char *dir = malloc( dir_size );
-    if (dir && !sysctl( pathname, ARRAY_SIZE( pathname ), dir, &dir_size, NULL, 0 ))
+    if (dir && !sysctl( pathname, sizeof(pathname)/sizeof(pathname[0]), dir, &dir_size, NULL, 0 ))
         return dir;
     free( dir );
     return NULL;
