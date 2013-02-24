--- fb.c.orig	2013-02-24 14:29:59.000000000 +0100
+++ fb.c	2013-02-24 14:30:35.000000000 +0100
@@ -16,7 +16,7 @@
 #  include <sys/mnttab.h>
 #  include <sys/vfstab.h>
 # elif defined(__FreeBSD__)
-/* #  include <mntent.h> */
+#  include "mntent.h"
 # else
 #  include <mntent.h>
 # endif
@@ -1254,8 +1254,6 @@ static GList *FileBrowserGetDrivePaths(v
 	}
 
 	return(paths_list);
-#elif defined(__FreeBSD__)
-	return(NULL);
 #else	/* UNIX */
 	GList *paths_list = NULL;
 #ifdef __SOLARIS__
