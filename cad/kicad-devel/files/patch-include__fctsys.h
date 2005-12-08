--- ./include/fctsys.h.orig	Tue Mar 22 15:30:28 2005
+++ ./include/fctsys.h	Thu Dec  1 21:50:58 2005
@@ -18,8 +18,12 @@
 #endif
 
 #include <stdio.h>
-#ifndef __DARWIN__
-#include <malloc.h>		// MacOSX (DARWIN): malloc() and free() are in stdlib.h
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
+# ifndef __DARWIN__
+# include <malloc.h>		// MacOSX (DARWIN): malloc() and free() are in stdlib.h
+# endif
 #endif
 #include <time.h>
 #include <math.h>
