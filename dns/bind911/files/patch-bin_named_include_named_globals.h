We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2018-10-06 01:36:17 UTC
+++ bin/named/include/named/globals.h
@@ -139,7 +139,7 @@ EXTERN bool		ns_g_forcelock		INIT(false)
 #if NS_RUN_PID_DIR
 EXTERN const char *		ns_g_defaultpidfile 	INIT(NS_LOCALSTATEDIR
 							     "/run/named/"
-							     "named.pid");
+							     "pid");
 EXTERN const char *		lwresd_g_defaultpidfile INIT(NS_LOCALSTATEDIR
 							     "/run/lwresd/"
 							     "lwresd.pid");
