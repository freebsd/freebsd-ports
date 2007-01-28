--- ace/os_include/os_pthread.h.orig	Tue May 30 16:15:53 2006
+++ ace/os_include/os_pthread.h	Sun Jan 28 13:50:01 2007
@@ -339,7 +339,11 @@
 #    undef THR_DAEMON
 
 #    define THR_BOUND               0x00000001
+# if defined (__FreeBSD__)
+#    define THR_NEW_LWP             0x00000000
+# else
 #    define THR_NEW_LWP             0x00000002
+# endif
 #    define THR_DETACHED            0x00000040
 #    define THR_SUSPENDED           0x00000080
 #    define THR_DAEMON              0x00000100
