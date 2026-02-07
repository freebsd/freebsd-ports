From: Marcin Owsiany <marcin@owsiany.pl>
Subject: Fix symlink update detection
Bug-Debian: https://bugs.debian.org/1005943

--- unix/unix.c.orig	2008-06-19 04:26:18 UTC
+++ unix/unix.c
@@ -423,7 +423,7 @@ ulg filetime(f, a, n, t)
     }
   }
   if (n != NULL)
-    *n = (s.st_mode & S_IFMT) == S_IFREG ? s.st_size : -1L;
+    *n = ((s.st_mode & S_IFMT) == S_IFREG || (s.st_mode & S_IFMT) == S_IFLNK) ? s.st_size : -1L;
   if (t != NULL) {
     t->atime = s.st_atime;
     t->mtime = s.st_mtime;
