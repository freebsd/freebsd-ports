
$FreeBSD$

--- ckuath.c.orig	Thu Feb 14 21:31:55 2002
+++ ckuath.c	Thu Feb 14 21:32:23 2002
@@ -114,7 +114,9 @@
 #include <stdio.h>
 #include <time.h>
 #include <fcntl.h>
+#ifndef FREEBSD4
 #include <malloc.h>
+#endif
 #ifdef OS2
 #include <io.h>
 #endif /* OS2 */
