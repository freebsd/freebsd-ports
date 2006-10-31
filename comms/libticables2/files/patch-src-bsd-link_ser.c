--- src/bsd/link_ser.c.orig	Wed Oct 11 15:11:06 2006
+++ src/bsd/link_ser.c	Wed Oct 11 15:12:04 2006
@@ -26,6 +26,7 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 
 #include "../ticables.h"
@@ -39,21 +40,23 @@
 
 static int ser_prepare(CableHandle *h)
 {
+    int ret;
+
     switch(h->port)
     {
-    case PORT_1: h->address = 0x3f8; h->device = strdup("/dev/cuaa0");
+    case PORT_1: h->address = 0x3f8; h->device = strdup("/dev/cuad0");
 	break;
-    case PORT_2: h->address = 0x2f8; h->device = strdup("/dev/cuaa1");
+    case PORT_2: h->address = 0x2f8; h->device = strdup("/dev/cuad1");
 	break;
-    case PORT_3: h->address = 0x3e8; h->device = strdup("/dev/cuaa2");
+    case PORT_3: h->address = 0x3e8; h->device = strdup("/dev/cuad2");
 	break;
-    case PORT_4: h->address = 0x3e8; h->device = strdup("/dev/cuaa3");
+    case PORT_4: h->address = 0x3e8; h->device = strdup("/dev/cuad3");
 	break;
     default: return ERR_ILLEGAL_ARG;
     }
 
     // detect stuffs
-    err = check_for_tty(h->device));
+    ret = check_for_tty(h->device);
 	if(ret)
 	{
 		free(h->device); h->device = NULL;
