We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2025-04-09 14:26:29 UTC
+++ bin/named/include/named/globals.h
@@ -117,7 +117,7 @@ EXTERN const char *named_g_defaultpidfile INIT(NAMED_L
 
 #if NAMED_RUN_PID_DIR
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/named/"
-								   "named.pid");
+								   "pid");
 #else  /* if NAMED_RUN_PID_DIR */
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/"
 								   "named.pid");
