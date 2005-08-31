--- mtest.c.orig	Sat Aug 20 16:05:55 2005
+++ mtest.c	Sat Aug 20 16:06:01 2005
@@ -27,7 +27,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <memory.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #ifndef WIN32
 # include <getopt.h>
