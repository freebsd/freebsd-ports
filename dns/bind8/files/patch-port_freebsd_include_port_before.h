--- src/port/freebsd/include/port_before.h.orig	Wed Oct 31 23:29:21 2001
+++ src/port/freebsd/include/port_before.h	Tue Feb 26 21:50:52 2002
@@ -15,6 +15,7 @@
 #define SETPWENT_VOID
 #endif
 
+#include <sys/param.h>
 #include <sys/types.h>
 
 #define GROUP_R_RETURN struct group *
@@ -26,8 +27,14 @@
 #define GROUP_R_ENT_ARGS void
 #define GROUP_R_OK gptr
 #define GROUP_R_BAD NULL
+
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 500030
+#define GETGROUPLIST_ARGS const char *name, gid_t basegid, gid_t *groups, \
+			  int *ngroups
+#else
 #define GETGROUPLIST_ARGS const char *name, int basegid, int *groups, \
 			  int *ngroups
+#endif
 
 #define HOST_R_RETURN struct hostent *
 #define HOST_R_SET_RETURN void
