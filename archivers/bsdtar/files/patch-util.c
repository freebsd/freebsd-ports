$FreeBSD$

--- util.c.orig	Tue Sep  6 10:24:36 2005
+++ util.c	Tue Sep  6 10:24:54 2005
@@ -29,6 +29,7 @@
 
 #include <sys/stat.h>
 #include <sys/types.h>  /* Linux doesn't define mode_t, etc. in sys/stat.h. */
+#include <wchar.h>
 #include <archive_entry.h>
 #include <ctype.h>
 #include <errno.h>
