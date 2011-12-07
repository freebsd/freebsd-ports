--- plugins/zynaddsubfx/fltk/src/numericsort.c	2011-09-27 12:20:36.000000000 +0000
+++ plugins/zynaddsubfx/fltk/src/numericsort.c.new	2011-09-27 12:26:57.000000000 +0000
@@ -34,20 +34,7 @@
 #include <sys/types.h>
 
 #if !defined(WIN32) || defined(__CYGWIN__)
-#  ifdef HAVE_DIRENT_H
-#    include <dirent.h>
-#  else
-#    define dirent direct
-#    if HAVE_SYS_NDIR_H
-#      include <sys/ndir.h>
-#    endif /* HAVE_SYS_NDIR_H */
-#    if HAVE_SYS_DIR_H
-#      include <sys/dir.h>
-#    endif /* HAVE_SYS_DIR_H */
-#    if HAVE_NDIR_H
-#      include <ndir.h>
-#    endif /* HAVE_NDIR_H */
-#  endif /* HAVE_DIRENT_H */
+#  include <dirent.h>
 #else /* For WIN32 variants */
 #  include <FL/filename.H>
 #endif /* !WIN32 || __CYGWIN__ */
