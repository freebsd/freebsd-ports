--- freecell/gdk-card-image/gdk-card-image.c.orig	Tue Jul 23 20:46:35 2002
+++ freecell/gdk-card-image/gdk-card-image.c	Tue Jul 23 20:52:20 2002
@@ -27,13 +27,8 @@
 
 #include <config.h>
 #include <gnome.h>
-#ifdef HAVE_SYS_DIRENT_H
-#include <sys/dirent.h>
-#elif defined(HAVE_SYS_DIR_H)
-#include <sys/dir.h>
-#else
+#include <sys/types.h>
 #include <dirent.h>
-#endif
 
 #ifdef __osf__
 #undef HAVE_STRUCT_DIRECT
