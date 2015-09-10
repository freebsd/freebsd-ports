--- libgphoto2_port/gphoto2/gphoto2-port-portability.h.orig	2014-06-27 05:26:01 UTC
+++ libgphoto2_port/gphoto2/gphoto2-port-portability.h
@@ -174,20 +174,6 @@ typedef struct {
 
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
