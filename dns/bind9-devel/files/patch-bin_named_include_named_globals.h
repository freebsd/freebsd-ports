We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2018-05-18 05:44:02 UTC
+++ bin/named/include/named/globals.h
@@ -126,7 +126,7 @@ EXTERN isc_boolean_t		named_g_forcelock	
 #if NAMED_RUN_PID_DIR
 EXTERN const char *		named_g_defaultpidfile 	INIT(NAMED_LOCALSTATEDIR
 							     "/run/named/"
-							     "named.pid");
+							     "pid");
 #else
 EXTERN const char *		named_g_defaultpidfile 	INIT(NAMED_LOCALSTATEDIR
 							     "/run/named.pid");
