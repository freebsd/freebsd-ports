--- include/vki/vki-freebsd.h.orig	2015-01-26 16:17:32.000000000 -0400
+++ include/vki/vki-freebsd.h	2015-08-31 04:55:29.139189000 -0300
@@ -684,6 +684,7 @@
 
 #define VKI_SOCK_STREAM	1
 
+#include <sys/types.h>
 #include <netinet/tcp.h>
 
 #define VKI_TCP_NODELAY  TCP_NODELAY
@@ -1888,11 +1889,23 @@
 #define VKI_I386_SET_FSBASE     8
 #define VKI_I386_GET_GSBASE     9
 #define VKI_I386_SET_GSBASE     10
+#define VKI_I386_SET_XFPUSTATE	11
 
 #define VKI_AMD64_GET_FSBASE    128
 #define VKI_AMD64_SET_FSBASE    129
 #define VKI_AMD64_GET_GSBASE    130
 #define VKI_AMD64_SET_GSBASE    131
+#define	VKI_AMD64_GET_XFPUSTATE	132
+
+typedef struct vki_i386_get_xfpustate {
+	unsigned int addr;
+	int len;
+};
+
+typedef struct vki_amd64_get_xfpustate {
+	void *addr;
+	int len;
+};
 
 //----------------------------------------------------------------------
 // From sys/module.h
