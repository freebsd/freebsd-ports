--- src/security/ggz_tls_gnutls.c.orig	Wed Jun  2 11:39:55 2004
+++ src/security/ggz_tls_gnutls.c	Wed Jun  2 11:40:23 2004
@@ -35,6 +35,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <gnutls.h>
+#include <gnutls/compat4.h>
 
 #include "ggz.h"
 
