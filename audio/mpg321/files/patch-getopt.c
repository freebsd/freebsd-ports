
$FreeBSD$

--- getopt.c.orig	Mon Oct 15 14:05:23 2001
+++ getopt.c	Mon Oct 15 14:05:37 2001
@@ -76,16 +76,7 @@
 # endif
 #endif
 
-#ifndef _
-/* This is for other GNU distributions with internationalized messages.
-   When compiling libc, the _ macro is predefined.  */
-# ifdef HAVE_LIBINTL_H
-#  include <libintl.h>
-#  define _(msgid)	gettext (msgid)
-# else
 #  define _(msgid)	(msgid)
-# endif
-#endif
 
 /* This version of `getopt' appears to the caller like standard Unix `getopt'
    but it behaves differently for the user, since it allows the user
