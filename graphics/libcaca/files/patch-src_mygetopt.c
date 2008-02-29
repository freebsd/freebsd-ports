--- src/mygetopt.c.orig	2008-02-29 16:41:07.000000000 -0600
+++ src/mygetopt.c	2008-02-29 16:41:23.000000000 -0600
@@ -25,7 +25,7 @@
 #endif
 
 /* DOS / Kernel driver */
-#ifndef __intptr_t_defined
+#ifndef _INTPTR_T_DECLARED
 typedef unsigned int		uintptr_t;
 #endif
 
