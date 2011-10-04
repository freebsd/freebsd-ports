--- sasl_defs.c.orig	2011-10-01 18:09:22.000000000 +0000
+++ sasl_defs.c	2011-10-01 18:10:33.000000000 +0000
@@ -3,6 +3,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sasl/saslplug.h>
 
 #ifdef HAVE_SASL_CB_GETCONF
 /* The locations we may search for a SASL config file if the user didn't
@@ -141,7 +142,7 @@
    { SASL_CB_SERVER_USERDB_CHECKPASS, sasl_server_userdb_checkpass, NULL },
 #endif
 
-   { SASL_CB_LOG, sasl_log, NULL },
+   { SASL_CB_LOG, (sasl_callback_ft)sasl_log, NULL },
 
 #ifdef HAVE_SASL_CB_GETCONF
    { SASL_CB_GETCONF, sasl_getconf, NULL },
