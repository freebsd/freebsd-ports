--- audio.c	2005-11-27 16:55:24.000000000 +0800
+++ audio.c	2008-05-24 22:12:15.000000000 +0800
@@ -31,20 +31,8 @@
 #include <string.h>
 #include <sys/types.h>
 
-#ifdef _WIN32
-#include <io.h>
-#else
-# ifndef __MACOSX__
-#  include <sys/io.h>
-# endif
-#endif
-
 #include <fcntl.h>
 
-#ifndef __MACOSX__
-#include <malloc.h>
-#endif
-
 #include <math.h>
 #include "config.h"
 #include "audio.h"
