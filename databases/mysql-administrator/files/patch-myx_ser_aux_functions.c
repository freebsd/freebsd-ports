--- mysql-gui-common/library/source/myx_ser_aux_functions.c.orig	Sat Aug 28 00:20:08 2004
+++ mysql-gui-common/library/source/myx_ser_aux_functions.c	Sat Aug 28 00:20:31 2004
@@ -18,6 +18,7 @@
 #include <glib.h>
 #include <string.h>
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 
 struct _MYX_SFD
