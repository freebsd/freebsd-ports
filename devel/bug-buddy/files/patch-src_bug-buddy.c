--- src/bug-buddy.c.orig	2010-09-27 16:25:15.000000000 +0200
+++ src/bug-buddy.c	2010-11-16 19:16:24.000000000 +0100
@@ -56,6 +56,10 @@
 
 #include <libsoup/soup.h>
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
+
 #define USE_PROXY_KEY 	"/system/http_proxy/use_http_proxy"
 #define PROXY_HOST_KEY	"/system/http_proxy/host"
 #define PROXY_PORT_KEY	"/system/http_proxy/port"
@@ -1955,10 +1959,12 @@
 			_exit(0);
 		}
 		
+#if !defined(__FreeBSD__) || __FreeBSD_version > 700024
 		if (!elf_has_debug_symbols (gopt_data.pid)) {
 			/* FIXME: Request PackageKit to install debug symbols packages */
 			_exit(0);
 		}
+#endif
 
 	}
 
