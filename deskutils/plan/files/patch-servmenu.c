--- servmenu.c.orig	2005-05-18 16:01:40.000000000 -0300
+++ servmenu.c	2009-10-05 22:16:45.000000000 -0300
@@ -8,7 +8,7 @@
 
 #include <stdio.h>
 #include <time.h>
-#ifndef MACOSX
+#ifndef STDLIBMALLOC
 #include <malloc.h>
 #else
 #include <stdlib.h>
