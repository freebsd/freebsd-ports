https://bugs.winehq.org/show_bug.cgi?id=50255

--- server/fd.c.orig	2020-12-05 16:14:40.336431000 +0000
+++ server/fd.c	2020-12-05 16:14:42.435171000 +0000
@@ -1982,8 +1982,10 @@
     }
     else rw_mode = O_RDONLY;
 
+#if defined(O_SYMLINK)
     if ((options & FILE_OPEN_REPARSE_POINT) && !(flags & O_CREAT))
         flags |= O_SYMLINK;
+#endif
 
     if ((fd->unix_fd = open( name, rw_mode | (flags & ~O_TRUNC), *mode )) == -1)
     {
