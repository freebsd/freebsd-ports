We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2019-02-05 00:00:59 UTC
+++ bin/named/include/named/globals.h
@@ -129,7 +129,7 @@ EXTERN bool		named_g_forcelock	INIT(false);
 #if NAMED_RUN_PID_DIR
 EXTERN const char *		named_g_defaultpidfile 	INIT(NAMED_LOCALSTATEDIR
 							     "/run/named/"
-							     "named.pid");
+							     "pid");
 #else
 EXTERN const char *		named_g_defaultpidfile 	INIT(NAMED_LOCALSTATEDIR
 							     "/run/named.pid");
