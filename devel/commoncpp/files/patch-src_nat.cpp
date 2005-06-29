--- src/nat.cpp.orig	Tue Jun 28 23:19:51 2005
+++ src/nat.cpp	Tue Jun 28 23:26:15 2005
@@ -127,6 +127,9 @@
 #else
 # define NAT_SYSCALL "ioctl"
 # ifdef HAVE_NAT_IPF
+#  ifndef IPL_NAT
+#   define IPL_NAT IPNAT_NAME
+#  endif
 #  define NAT_DEVICE IPL_NAT
 # else
 #  ifdef HAVE_NAT_PF
