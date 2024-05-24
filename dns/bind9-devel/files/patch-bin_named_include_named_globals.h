We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2023-12-01 14:21:34 UTC
+++ bin/named/include/named/globals.h
@@ -121,7 +121,7 @@ EXTERN const char *named_g_defaultsessionkeyfile INIT(
 
 #if NAMED_RUN_PID_DIR
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/named/"
-								   "named.pid");
+								   "pid");
 #else  /* if NAMED_RUN_PID_DIR */
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/"
 								   "named.pid");
