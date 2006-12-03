--- ace/os_include/os_pthread.h.orig	Sun Dec  3 21:47:36 2006
+++ ace/os_include/os_pthread.h	Sun Dec  3 21:51:19 2006
@@ -345,7 +345,7 @@
 #    undef THR_DAEMON
 
 #    define THR_BOUND               0x00000001
-#    if defined (CHORUS)
+#    if defined (CHORUS) || (__FreeBSD__)
 #      define THR_NEW_LWP             0x00000000
 #    else
 #      define THR_NEW_LWP             0x00000002
