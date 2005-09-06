$FreeBSD$

--- write.c.orig	Tue Sep  6 10:24:40 2005
+++ write.c	Tue Sep  6 10:25:01 2005
@@ -32,6 +32,7 @@
 #ifdef HAVE_POSIX_ACL
 #include <sys/acl.h>
 #endif
+#include <wchar.h>
 #include <archive.h>
 #include <archive_entry.h>
 #include <errno.h>
