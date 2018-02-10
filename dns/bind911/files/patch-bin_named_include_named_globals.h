We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2018-01-04 05:28:11 UTC
+++ bin/named/include/named/globals.h
@@ -135,7 +135,7 @@ EXTERN isc_boolean_t		ns_g_forcelock		IN
 #if NS_RUN_PID_DIR
 EXTERN const char *		ns_g_defaultpidfile 	INIT(NS_LOCALSTATEDIR
 							     "/run/named/"
-							     "named.pid");
+							     "pid");
 EXTERN const char *		lwresd_g_defaultpidfile INIT(NS_LOCALSTATEDIR
 							     "/run/lwresd/"
 							     "lwresd.pid");
