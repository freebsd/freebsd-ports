*** tty.c~	Sat Jun  7 16:32:21 1997
--- tty.c	Tue Sep 29 15:32:05 1998
***************
*** 23,28 ****
--- 23,30 ----
  # include	<sys/mkdev.h>
  # else		/* ! HAVE_SYS_SYSMACROS_H && ! HAVE_SYS_MKDEV_H */
+ # ifndef major
  # define	major(xx)	(((xx) >> 8) & 0xff)
  # define	minor(xx)	((xx) & 0xff)
+ # endif		/* major */
  # endif		/* HAVE_SYS_SYSMACROS_H || HAVE_SYS_MKDEV_H */
  # include	"pager.h"
