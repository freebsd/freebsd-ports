diff -Nur archivers/rpm4/files/patch-misc_fts.c archivers/rpm4/files/patch-misc_fts.c
--- archivers/rpm4/files/patch-misc_fts.c	1970-01-01 01:00:00.000000000 +0100
+++ archivers/rpm4/files/patch-misc_fts.c	2012-05-30 14:15:28.000000000 +0200
@@ -0,0 +1,30 @@
+--- misc/fts.c	2012-04-03 15:53:59.000000000 +0200
++++ misc/fts.c	2012-05-30 14:07:33.000000000 +0200
+@@ -31,13 +31,14 @@
+ static char sccsid[] = "@(#)fts.c	8.6 (Berkeley) 8/14/94";
+ #endif /* LIBC_SCCS and not lint */
+ 
++#include "system.h"
++#include "misc/fts.h"
+ #if defined(_LIBC)
+ #include <sys/param.h>
+ #include <include/sys/stat.h>
+ #include <fcntl.h>
+ #include <dirent.h>
+ #include <errno.h>
+-#include "misc/fts.h"
+ #include <stdlib.h>
+ #include <string.h>
+ #include <unistd.h>
+@@ -61,11 +62,9 @@
+ #   define _STAT_VER		0
+ #   define __fxstat64(_stat_ver, _fd, _sbp) fstat64((_fd), (_sbp))
+ #endif
+-#include "system.h"
+ #include <stdlib.h>
+ #include <string.h>
+ #include <errno.h>
+-#include "misc/fts.h"
+ #   define __set_errno(val) (*__errno_location ()) = (val)
+ #   define __open	open
+ #   define __close	close