--- newlib/libc/sys/psp/arpa/inet.h.orig	1970-01-01 02:00:00.000000000 +0200
+++ newlib/libc/sys/psp/arpa/inet.h	2007-06-01 12:22:26.000000000 +0300
@@ -0,0 +1,26 @@
+/* arpa/inet.h - Functions for converting IP addresses between strings and numbers */
+
+#ifndef _ARPA_INET_H_
+#define _ARPA_INET_H_
+
+#ifdef __cplusplus
+extern "C" {
+#endif
+
+#include <netinet/in.h>
+
+in_addr_t sceNetInetInetAddr(const char *ip);
+int sceNetInetInetAton(const char *ip, struct in_addr *in);
+const char* sceNetInetInetNtop(int af, const void *src, char *dst, socklen_t cnt);
+int sceNetInetInetPton(int af, const char *src, void *dst);
+
+char *inet_ntoa(struct in_addr in);
+#define inet_addr sceNetInetInetAddr
+#define inet_aton sceNetInetInetAton
+#define inet_ntop sceNetInetInetNtop
+#define inet_pton sceNetInetInetPton
+
+#ifdef __cplusplus
+}
+#endif
+#endif /* _ARPA_INET_H_ */
