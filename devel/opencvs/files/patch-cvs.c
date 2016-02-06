--- cvs.c.orig	2016-02-06 23:39:08.240246000 +0100
+++ cvs.c	2016-02-06 23:39:10.243855000 +0100
@@ -187,8 +187,10 @@ main(int argc, char **argv)
 	struct stat st;
 	char fpath[PATH_MAX];
 
+#if 0
 	if (pledge("stdio rpath wpath cpath fattr proc exec", NULL) == -1)
 		err(1, "pledge");
+#endif
 
 	tzset();
 
