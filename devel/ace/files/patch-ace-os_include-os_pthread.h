--- ace/os_include/os_pthread.h.orig	2010-11-27 02:39:33.000000000 +0900
+++ ace/os_include/os_pthread.h	2011-11-27 05:58:00.000000000 +0900
@@ -283,7 +283,11 @@
 #  undef THR_DAEMON
 
 #  define THR_BOUND               0x00000001
+# if defined(__FreeBSD__)
+#  define THR_NEW_LWP             0x00000000
+# else
 #  define THR_NEW_LWP             0x00000002
+# endif
 #  define THR_DAEMON              0x00000010
 #  define THR_DETACHED            0x00000040
 #  define THR_SUSPENDED           0x00000080
