--- src/clients/lib/java/misc.c.orig	Sat Oct  7 14:41:07 2006
+++ src/clients/lib/java/misc.c	Sat Oct  7 14:41:16 2006
@@ -15,6 +15,7 @@
  */
 
 #include <stdio.h>
+#include <sys/syslimits.h>
 #include <xmmsclient/xmmsclient.h>
 #include <xmms/xmms_defs.h>
 #include <jni.h>
