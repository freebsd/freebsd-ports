We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2025-10-18 09:48:52 UTC
+++ bin/named/include/named/globals.h
@@ -112,7 +112,7 @@ EXTERN const char *named_g_defaultpidfile INIT(NAMED_L
 
 #if NAMED_RUN_PID_DIR
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/named/"
-								   "named.pid");
+								   "pid");
 #else  /* if NAMED_RUN_PID_DIR */
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/"
 								   "named.pid");
