--- mysqladministrator/source/linux/MInstanceInfo.cc.orig	Wed Feb 11 22:38:41 2004
+++ mysqladministrator/source/linux/MInstanceInfo.cc	Tue Feb 24 03:45:50 2004
@@ -24,9 +24,15 @@
 #include "myx_aux_functions.h"
 #include "myx_admin_public_interface.h"
 
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/mount.h>
+#else
 #include <sys/statfs.h>
 #include <sys/vfs.h>
+#endif
 #include <stdio.h>
+#include <errno.h>
 
 struct FSType {
   long id;
