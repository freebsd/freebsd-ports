--- InOut/rtalsa.c.orig	2015-09-29 11:13:27 UTC
+++ InOut/rtalsa.c
@@ -23,6 +23,7 @@
     02111-1307 USA
 */
 
+/*
 #ifndef _ISOC99_SOURCE
 #define _ISOC99_SOURCE 1
 #endif
@@ -32,6 +33,7 @@
 #ifndef _BSD_SOURCE
 #define _BSD_SOURCE 1
 #endif
+*/
 
 #include "csdl.h"
 
@@ -50,6 +52,8 @@
 #include <signal.h>
 #include <sys/mman.h>
 #include <sys/resource.h>
+#include <stdlib.h>
+#include <sys/fcntl.h>
 
 
 #include "soundio.h"
