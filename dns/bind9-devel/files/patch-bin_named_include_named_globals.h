We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2024-12-03 09:47:47 UTC
+++ bin/named/include/named/globals.h
@@ -118,7 +118,7 @@ EXTERN const char *named_g_defaultsessionkeyfile INIT(
 
 #if NAMED_RUN_PID_DIR
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/named/"
-								   "named.pid");
+								   "pid");
 #else  /* if NAMED_RUN_PID_DIR */
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/"
 								   "named.pid");
