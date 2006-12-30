--- lib/getopt.c.orig	Thu Feb 28 10:30:01 2002
+++ lib/getopt.c	Tue Dec 26 13:39:53 2006
@@ -76,7 +76,7 @@
 # endif
 #endif
 
-#ifndef _
+#if defined(PR_USE_NLS) && !defined(_)
 /* This is for other GNU distributions with internationalized messages.
    When compiling libc, the _ macro is predefined.  */
 # ifdef HAVE_LIBINTL_H
@@ -85,6 +85,8 @@
 # else
 #  define _(msgid)	(msgid)
 # endif
+#else
+# define _(msgid)	(msgid)
 #endif
 
 /* This version of `getopt' appears to the caller like standard Unix `getopt'
