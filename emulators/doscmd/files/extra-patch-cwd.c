This call changes internal descriptor in DIR structure so it's
located at the top of file descriptor table. I guess it is needed
to not interfere with other file descriptor order or to keep their
values small. doscmd may work fine without it, but it should be
tested.
--- cwd.c.orig	2011-08-26 16:48:21 UTC
+++ cwd.c
@@ -889,7 +889,7 @@ find_first(u_char *path, int attr, dosdi
 	++search->searchend;
     *search->searchend++ = '/';
 
-    search->dp->dd_fd = squirrel_fd(search->dp->dd_fd);
+    //search->dp->dd_fd = squirrel_fd(search->dp->dd_fd);
 
     dta->drive = drive | 0x80;
     to_dos_fcb(dta->pattern, slash);
