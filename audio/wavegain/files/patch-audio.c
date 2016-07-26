--- audio.c.orig	2016-07-26 16:16:05 UTC
+++ audio.c
@@ -32,20 +32,8 @@
 #include <sys/types.h>
 #include <math.h>
 
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
 #include "config.h"
 #include "audio.h"
 #include "i18n.h"
