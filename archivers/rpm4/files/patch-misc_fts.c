--- misc/fts.c.orig	2014-06-30 08:47:14 UTC
+++ misc/fts.c
@@ -31,13 +31,14 @@
 static char sccsid[] = "@(#)fts.c	8.6 (Berkeley) 8/14/94";
 #endif /* LIBC_SCCS and not lint */
 
+#include "system.h"
+#include "misc/fts.h"
 #if defined(_LIBC)
 #include <sys/param.h>
 #include <include/sys/stat.h>
 #include <fcntl.h>
 #include <dirent.h>
 #include <errno.h>
-#include "misc/fts.h"
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
@@ -61,11 +62,9 @@ static char sccsid[] = "@(#)fts.c	8.6 (B
 #   define _STAT_VER		0
 #   define __fxstat64(_stat_ver, _fd, _sbp) fstat64((_fd), (_sbp))
 #endif
-#include "system.h"
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
-#include "misc/fts.h"
 #   define __set_errno(val) (*__errno_location ()) = (val)
 #   define __open	open
 #   define __close	close
