--- plugins/zynaddsubfx/fltk/src/scandir.c	2011-06-09 08:34:59.000000000 +0000
+++ plugins/zynaddsubfx/fltk/src/scandir.c.new	2011-08-08 11:43:43.000000000 +0000
@@ -28,22 +28,8 @@
 #    include <sys/types.h>
 #    include <errno.h>
 
-#    if HAVE_DIRENT_H
-#      include <dirent.h>
-#      define NAMLEN(dirent) strlen((dirent)->d_name)
-#    else
-#      define dirent direct
-#      define NAMLEN(dirent) (dirent)->d_namlen
-#      if HAVE_SYS_NDIR_H
-#        include <sys/ndir.h>
-#      endif
-#      if HAVE_SYS_DIR_H
-#        include <sys/dir.h>
-#      endif
-#      if HAVE_NDIR_H
-#        include <ndir.h>
-#      endif
-#    endif
+#    include <dirent.h>
+#    define NAMLEN(dirent) strlen((dirent)->d_name)
 
 int
 fl_scandir(const char *dir, struct dirent ***namelist,
