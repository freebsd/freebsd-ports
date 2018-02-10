We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2018-01-17 06:56:09 UTC
+++ bin/named/include/named/globals.h
@@ -125,7 +125,7 @@ EXTERN isc_boolean_t		named_g_forcelock	
 #if NAMED_RUN_PID_DIR
 EXTERN const char *		named_g_defaultpidfile 	INIT(NAMED_LOCALSTATEDIR
 							     "/run/named/"
-							     "named.pid");
+							     "pid");
 #else
 EXTERN const char *		named_g_defaultpidfile 	INIT(NAMED_LOCALSTATEDIR
 							     "/run/named.pid");
