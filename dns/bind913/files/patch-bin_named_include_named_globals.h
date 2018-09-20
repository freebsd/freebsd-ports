We reference the pid file as being run/named/pid everywere else.

--- bin/named/include/named/globals.h.orig	2018-09-06 00:15:26 UTC
+++ bin/named/include/named/globals.h
@@ -128,7 +128,7 @@ EXTERN bool		named_g_forcelock	INIT(fals
 #if NAMED_RUN_PID_DIR
 EXTERN const char *		named_g_defaultpidfile 	INIT(NAMED_LOCALSTATEDIR
 							     "/run/named/"
-							     "named.pid");
+							     "pid");
 #else
 EXTERN const char *		named_g_defaultpidfile 	INIT(NAMED_LOCALSTATEDIR
 							     "/run/named.pid");
