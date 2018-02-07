We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2018-01-04 05:35:08 UTC
+++ bin/named/include/named/globals.h
@@ -136,7 +136,7 @@ EXTERN const char *		ns_g_defaultsession
 #if NS_RUN_PID_DIR
 EXTERN const char *		ns_g_defaultpidfile 	INIT(NS_LOCALSTATEDIR
 							     "/run/named/"
-							     "named.pid");
+							     "pid");
 EXTERN const char *		lwresd_g_defaultpidfile INIT(NS_LOCALSTATEDIR
 							     "/run/lwresd/"
 							     "lwresd.pid");
