We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2020-02-12 20:03:44 UTC
+++ bin/named/include/named/globals.h
@@ -127,7 +127,7 @@ EXTERN bool named_g_forcelock		   INIT(false);
 
 #if NAMED_RUN_PID_DIR
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/named/"
-								   "named.pid");
+								   "pid");
 #else
 EXTERN const char *named_g_defaultpidfile INIT(NAMED_LOCALSTATEDIR "/run/"
 								   "named.pid");
