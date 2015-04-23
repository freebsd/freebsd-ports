--- src/optipng/osys.c.orig	2015-04-22 09:09:17 UTC
+++ src/optipng/osys.c
@@ -518,7 +518,7 @@ osys_copy_attr(const char *src_path, con
     if (chmod(dest_path, sbuf.st_mode) != 0)
         result = -1;
 
-#ifdef AT_FDCWD
+#if 0
     {
         struct timespec times[2];
 
