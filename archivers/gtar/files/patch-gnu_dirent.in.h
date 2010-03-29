$FreeBSD$

7.x up to 7.3 lacks the fdopendir() prototype in <dirent.h>.

--- gnu/dirent.in.h.orig	2010-03-29 17:48:45.000000000 +0200
+++ gnu/dirent.in.h	2010-03-29 17:49:00.000000000 +0200
@@ -79,9 +79,7 @@ _GL_WARN_ON_USE (dirfd, "dirfd is unport
 _GL_FUNCDECL_RPL (fdopendir, DIR *, (int fd));
 _GL_CXXALIAS_RPL (fdopendir, DIR *, (int fd));
 # else
-#  if !@HAVE_FDOPENDIR@
 _GL_FUNCDECL_SYS (fdopendir, DIR *, (int fd));
-#  endif
 _GL_CXXALIAS_SYS (fdopendir, DIR *, (int fd));
 # endif
 _GL_CXXALIASWARN (fdopendir);
