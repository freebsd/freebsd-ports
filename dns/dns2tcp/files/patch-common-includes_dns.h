--- common/includes/dns.h.orig	2008-10-29 16:35:26.000000000 +0100
+++ common/includes/dns.h	2009-03-21 13:34:08.000000000 +0100
@@ -30,6 +30,10 @@
 #endif
 #include "base64.h"
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
+
 #define MAX_REQ_LEN			512
 
 #define MAX_HOST_NAME_ENCODED		200 
@@ -140,7 +144,9 @@
 void	dns_encode(char *);
 void	*jump_end_query(void *, int, int);
 #ifndef _WIN32
+#if !defined(__FreeBSD__) || __FreeBSD_version < 800067
 int	strnlen(char *, int len);
 #endif
+#endif
 
 #endif
--- server/includes/server.h.orig	2009-03-21 13:27:34.000000000 +0100
+++ server/includes/server.h	2009-03-21 13:28:21.000000000 +0100
@@ -48,7 +48,9 @@
 }			t_conf;
 
 int	do_server(t_conf *);
+#if !defined(__FreeBSD__) || __FreeBSD_version < 800067
 int	strnlen(char *, int); /* not present ?*/
+#endif
 int	delete_client(t_conf *conf, struct s_simple_list *client);
 void	delete_zombie(t_conf *conf);
 
