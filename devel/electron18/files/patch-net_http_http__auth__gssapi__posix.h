--- net/http/http_auth_gssapi_posix.h.orig	2022-05-19 03:45:36 UTC
+++ net/http/http_auth_gssapi_posix.h
@@ -20,6 +20,9 @@
 #if BUILDFLAG(IS_APPLE)
 #include <GSS/gssapi.h>
 #elif BUILDFLAG(IS_FREEBSD)
+#ifndef GSS_C_DELEG_POLICY_FLAG
+#define GSS_C_DELEG_POLICY_FLAG 32768
+#endif
 #include <gssapi/gssapi.h>
 #else
 #include <gssapi.h>
