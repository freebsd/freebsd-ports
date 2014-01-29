--- InOut/rtalsa.c.orig	2011-12-22 19:41:53.000000000 +0900
+++ InOut/rtalsa.c	2011-12-27 23:53:00.000000000 +0900
@@ -23,6 +23,7 @@
     02111-1307 USA
 */
 
+/*
 #ifndef _ISOC99_SOURCE
 #define _ISOC99_SOURCE 1
 #endif
@@ -39,6 +40,7 @@
 #ifndef _POSIX_C_SOURCE
 #define _POSIX_C_SOURCE 1
 #endif
+*/
 
 #include "csdl.h"
 
@@ -57,6 +59,8 @@
 #include <signal.h>
 #include <sys/mman.h>
 #include <sys/resource.h>
+#include <stdlib.h>
+#include <sys/fcntl.h>
 
 
 #include "soundio.h"
