--- src/utils.c.orig	2020-07-10 20:54:00 UTC
+++ src/utils.c
@@ -12,9 +12,9 @@
 
 #ifdef BSD_LIKE
 /* Needed for SIGWINCH on OpenBSD. */
-# define _BSD_SOURCE
+# define _BSD_SOURCE 1
 /* Needed for SIGWINCH on FreeBSD. */
-# define __BSD_VISIBLE
+# define __BSD_VISIBLE 1
 /* Needed for SIGWINCH on Darwin. */
 # define _DARWIN_C_SOURCE 1
 #endif
