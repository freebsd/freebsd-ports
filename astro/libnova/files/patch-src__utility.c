--- src/utility.c.orig	Sun Oct  9 11:04:48 2005
+++ src/utility.c	Sun Oct  9 11:04:56 2005
@@ -45,10 +45,6 @@
 #include <ctype.h>
 #include <libnova/utility.h>
 
-#ifndef __APPLE__
-#include <malloc.h>
-#endif
-
 #ifndef WIN32
 #include "config.h"
 #else
