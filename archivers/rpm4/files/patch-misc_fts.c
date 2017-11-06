--- misc/fts.c.orig	2016-11-30 07:03:00 UTC
+++ misc/fts.c
@@ -32,12 +32,14 @@ static char sccsid[] = "@(#)fts.c	8.6 (B
 #endif /* LIBC_SCCS and not lint */
 
 /* Conditional to set up proper fstat64 implementation */
-#if defined(hpux) || defined(sun)
+#if defined(hpux) || defined(__FreeBSD__) || defined(sun)
 #   define FTS_FSTAT64(_fd, _sbp)   fstat((_fd), (_sbp))
 #else
 #   define FTS_FSTAT64(_fd, _sbp)   fstat64((_fd), (_sbp))
 #endif
 
+#include "system.h"
+#include "misc/fts.h"
 #if defined(_LIBC)
 #include <sys/param.h>
 #include <include/sys/stat.h>
@@ -51,7 +53,7 @@ static char sccsid[] = "@(#)fts.c	8.6 (B
 #else
 
 /* Conditionals for working around non-GNU environments */
-#if defined(hpux)
+#if defined(hpux) || defined(__FreeBSD__)
 #   define        _INCLUDE_POSIX_SOURCE
 #   define __errno_location() 	(&errno)
 #   define dirfd(dirp)		-1
@@ -65,11 +67,9 @@ static char sccsid[] = "@(#)fts.c	8.6 (B
 #   define __errno_location()	(__error())
 #endif
 
-#include "system.h"
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
-#include "misc/fts.h"
 #   define __set_errno(val) (*__errno_location ()) = (val)
 #   define __open	open
 #   define __close	close
