--- lib/libBBS/dlm.c.orig	Tue Mar  8 02:12:24 2005
+++ lib/libBBS/dlm.c	Tue Mar  8 02:12:35 2005
@@ -3,7 +3,7 @@
 
 #ifndef BBS
   #include <dlfcn.h>
-  #include <varargs.h>
+  #include <stdarg.h>
   #include <strings.h>
   #include <stdlib.h>
   #include <stdio.h>
