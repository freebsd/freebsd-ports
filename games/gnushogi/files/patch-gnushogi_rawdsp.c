--- gnushogi/rawdsp.c.orig	2014-02-17 20:26:59 UTC
+++ gnushogi/rawdsp.c
@@ -35,7 +35,6 @@
 #include <stdarg.h>
 #include <sys/param.h>
 #include <sys/types.h>
-#include <sys/file.h>
 #ifndef WIN32
 #include <poll.h>
 #include <unistd.h>
@@ -44,11 +43,6 @@
 #include "gnushogi.h"
 #include "rawdsp.h"
 
-unsigned short MV[MAXDEPTH];
-int MSCORE;
-
-int mycnt1, mycnt2;
-char *DRAW;
 extern char *InPtr;
 extern short pscore[];
 
