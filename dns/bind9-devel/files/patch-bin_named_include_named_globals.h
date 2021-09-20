We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2021-09-17 07:10:48 UTC
+++ bin/named/include/named/globals.h
@@ -133,7 +133,7 @@ EXTERN bool named_g_forcelock		   INIT(false);
 
 #if NAMED_RUN_PID_DIR
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/named/"
-								   "named.pid");
+								   "pid");
 #else  /* if NAMED_RUN_PID_DIR */
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/"
 								   "named.pid");
