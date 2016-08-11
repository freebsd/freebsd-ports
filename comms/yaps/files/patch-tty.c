--- tty.c.orig	1997-06-07 14:32:21 UTC
+++ tty.c
@@ -22,8 +22,10 @@
 # elif		HAVE_SYS_MKDEV_H
 # include	<sys/mkdev.h>
 # else		/* ! HAVE_SYS_SYSMACROS_H && ! HAVE_SYS_MKDEV_H */
+# ifndef major
 # define	major(xx)	(((xx) >> 8) & 0xff)
 # define	minor(xx)	((xx) & 0xff)
+# endif		/* major */
 # endif		/* HAVE_SYS_SYSMACROS_H || HAVE_SYS_MKDEV_H */
 # include	"pager.h"
 /*}}}*/
