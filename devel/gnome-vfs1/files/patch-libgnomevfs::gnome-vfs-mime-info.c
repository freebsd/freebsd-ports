
$FreeBSD$

--- libgnomevfs/gnome-vfs-mime-info.c	2002/03/17 13:33:30	1.1
+++ libgnomevfs/gnome-vfs-mime-info.c	2002/03/17 13:33:39
@@ -46,7 +46,7 @@
 #include <time.h>
 #include <unistd.h>
 
-#include <iconv.h>
+#include <giconv.h>
 #include <errno.h>
 #include <stdlib.h>
 
