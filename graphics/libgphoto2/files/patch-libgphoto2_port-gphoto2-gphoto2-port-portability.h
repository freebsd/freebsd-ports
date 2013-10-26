--- libgphoto2_port/gphoto2/gphoto2-port-portability.h.orig	2011-04-05 08:38:24.000000000 +0200
+++ libgphoto2_port/gphoto2/gphoto2-port-portability.h	2013-10-26 11:13:54.000000000 +0200
@@ -152,20 +152,6 @@
 
 /* yummy. :) */
 
-/* XOPEN needed for usleep */
-#ifndef _XOPEN_SOURCE
-# define _XOPEN_SOURCE 500
-#else
-# if ((_XOPEN_SOURCE - 0) < 500)
-#  undef _XOPEN_SOURCE
-#  define _XOPEN_SOURCE 500
-# endif
-#endif
-
-/* for nanosleep */
-# ifndef _POSIX_C_SOURCE
-#  define _POSIX_C_SOURCE 199309
-# endif
 # include <time.h>
 
 # include <strings.h>
