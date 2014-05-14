--- src/OSD/OSD_SharedLibrary.cxx.orig	2014-04-29 11:40:36.000000000 +0200
+++ src/OSD/OSD_SharedLibrary.cxx	2014-05-04 14:21:09.000000000 +0200
@@ -25,7 +25,7 @@
 #include <stdio.h>
 
 #ifdef HAVE_MALLOC_H
-# include <malloc.h>
+# include <stdlib.h>
 #endif
 
 #ifdef __some_crappy_system__
