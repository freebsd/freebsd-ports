$FreeBSD$

--- read.c.orig	Tue Sep  6 10:22:45 2005
+++ read.c	Tue Sep  6 10:23:00 2005
@@ -30,6 +30,7 @@
 #include <sys/param.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <wchar.h>
 
 #include <archive.h>
 #include <archive_entry.h>
