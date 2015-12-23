--- src/psl.c.orig	2015-09-23 12:52:04 UTC
+++ src/psl.c
@@ -54,8 +54,10 @@
 #	define ngettext(STRING1,STRING2,N) STRING2
 #endif
 
-#include <sys/types.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 #include <sys/stat.h>
+#include <sys/types.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -87,7 +89,6 @@
 #endif
 
 #include <libpsl.h>
-#include <bits/stat.h>
 
 /* number of elements within an array */
 #define countof(a) (sizeof(a)/sizeof(*(a)))
