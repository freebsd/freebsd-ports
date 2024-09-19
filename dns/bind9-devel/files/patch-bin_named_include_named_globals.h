We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2024-09-09 13:09:11 UTC
+++ bin/named/include/named/globals.h
@@ -119,7 +119,7 @@ EXTERN const char *named_g_defaultsessionkeyfile INIT(
 
 #if NAMED_RUN_PID_DIR
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/named/"
-								   "named.pid");
+								   "pid");
 #else  /* if NAMED_RUN_PID_DIR */
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/"
 								   "named.pid");
