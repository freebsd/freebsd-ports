--- rest/oauth-proxy-call.c.orig	2015-02-24 01:13:22.000000000 +0100
+++ rest/oauth-proxy-call.c	2015-02-24 01:13:39.000000000 +0100
@@ -25,6 +25,7 @@
 #include <rest/rest-proxy-call.h>
 #include "oauth-proxy-call.h"
 #include "oauth-proxy-private.h"
+#include "rest-proxy-call-private.h"
 #include "sha1.h"
 
 G_DEFINE_TYPE (OAuthProxyCall, oauth_proxy_call, REST_TYPE_PROXY_CALL)
