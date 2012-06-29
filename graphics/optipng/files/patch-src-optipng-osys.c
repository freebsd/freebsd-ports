--- src/optipng/osys.c.orig	2011-07-22 13:49:00.000000000 +0900
+++ src/optipng/osys.c	2012-06-14 18:51:09.000000000 +0900
@@ -435,7 +435,7 @@
     if (chmod(dest_path, mode) != 0)
         return -1;
 
-#ifdef AT_FDCWD
+#if 0 /* def AT_FDCWD */
     {
         struct timespec times[2];
 
