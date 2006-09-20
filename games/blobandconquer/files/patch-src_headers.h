--- src/headers.h.orig	Tue May 30 23:08:58 2006
+++ src/headers.h	Tue May 30 23:09:11 2006
@@ -20,6 +20,7 @@
 
 #define GL_GLEXT_PROTOTYPES
 
+#include "unistd.h"
 #include "stdlib.h"
 #include "stdio.h"
 #include "string.h"
