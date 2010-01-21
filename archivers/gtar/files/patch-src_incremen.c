
$FreeBSD$

--- src/incremen.c.orig
+++ src/incremen.c
@@ -870,7 +870,7 @@
   time_t sec;
   long int nsec;
   char *buf = 0;
-  size_t bufsize;
+  size_t bufsize = 0;
   char *ebuf;
   long lineno = 1;
 
@@ -1230,7 +1230,7 @@
 {
   int fd;
   char *buf = 0;
-  size_t bufsize;
+  size_t bufsize = 0;
 
   /* Open the file for both read and write.  That way, we can write
      it later without having to reopen it, and don't have to worry if
