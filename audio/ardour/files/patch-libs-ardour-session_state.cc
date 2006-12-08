--- libs/ardour/session_state.cc.orig	Thu Dec  7 13:20:07 2006
+++ libs/ardour/session_state.cc	Thu Dec  7 13:22:03 2006
@@ -40,8 +40,9 @@
 #ifdef HAVE_SYS_VFS_H
 #include <sys/vfs.h>
 #else
-#include <sys/mount.h>
+// /usr/include/sys/ucred.h:71: error: `NGROUPS' was not declared in this scope
 #include <sys/param.h>
+#include <sys/mount.h>
 #endif
 
 #include <glibmm.h>
