--- lib/urldata.h.orig	2023-03-20 13:49:04 UTC
+++ lib/urldata.h
@@ -179,7 +179,7 @@ typedef CURLcode (*Curl_datastream)(struct Curl_easy *
 # elif defined HAVE_GSSAPI_GSSAPI_H
 #  include <gssapi/gssapi.h>
 # else
-#  include <gssapi.h>
+#  include <gssapi/gssapi.h>
 # endif
 # ifdef HAVE_GSSAPI_GSSAPI_GENERIC_H
 #  include <gssapi/gssapi_generic.h>
