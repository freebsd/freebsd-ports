--- InOut/rtalsa.c.orig	2018-11-07 14:05:23 UTC
+++ InOut/rtalsa.c
@@ -23,6 +23,7 @@
     02110-1301 USA
 */
 
+/*
 #ifndef _ISOC99_SOURCE
 #define _ISOC99_SOURCE 1
 #endif
@@ -36,6 +37,7 @@
 #ifndef _BSD_SOURCE
 #define _BSD_SOURCE 1
 #endif
+*/
 
 #include "csdl.h"
 
@@ -54,6 +56,8 @@
 #include <signal.h>
 #include <sys/mman.h>
 #include <sys/resource.h>
+#include <stdlib.h>
+#include <sys/fcntl.h>
 
 
 #include "soundio.h"
