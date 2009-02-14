--- audio.c.orig	2009-02-14 06:54:45.932023788 +0800
+++ audio.c	2009-02-14 06:55:01.958134649 +0800
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
