--- Wnn/jlib/js.c.orig	2007-11-11 17:46:58.000000000 +0900
+++ Wnn/jlib/js.c	2007-11-11 17:47:59.000000000 +0900
@@ -159,9 +159,9 @@
 */
 
 
-extern	char	*malloc();
-
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 #ifdef UX386
 #include <X11/Xos.h>
@@ -199,8 +199,6 @@
 #include "../etc/pwd.c"
 
 
-char *malloc();
-
 typedef struct _host_address {
 	int address_len;
 	char *address;
