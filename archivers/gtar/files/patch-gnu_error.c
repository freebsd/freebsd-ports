Fix remfiles01.at and remfiles02.at: error() needs to fetch the
name set by set_program_name().

--- gnu/error.c.orig	2017-12-16 21:23:33 UTC
+++ gnu/error.c
@@ -42,8 +42,6 @@
 # define USE_UNLOCKED_IO 0
 # define _GL_ATTRIBUTE_FORMAT_PRINTF(a, b)
 # define _GL_ARG_NONNULL(a)
-#else
-# include "getprogname.h"
 #endif
 
 #if USE_UNLOCKED_IO
@@ -119,7 +117,7 @@ int strerror_r (int errnum, char *buf, s
 #  endif
 # endif
 
-#define program_name getprogname ()
+extern char *program_name;
 
 # if GNULIB_STRERROR_R_POSIX || HAVE_STRERROR_R || defined strerror_r
 #  define __strerror_r strerror_r
