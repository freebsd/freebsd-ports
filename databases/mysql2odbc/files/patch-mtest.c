--- mtest.c.orig	Fri Jun 20 21:39:48 2003
+++ mtest.c	Tue Sep 13 18:21:18 2005
@@ -27,10 +27,10 @@
 #include <stdio.h>
 #include <string.h>
 #include <memory.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #ifndef WIN32
-# include <getopt.h>
+# include <unistd.h>
 #endif
 
 #ifdef FAKE
