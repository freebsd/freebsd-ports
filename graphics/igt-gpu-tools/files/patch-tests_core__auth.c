--- tests/core_auth.c.orig	2022-08-31 20:00:01 UTC
+++ tests/core_auth.c
@@ -48,6 +48,10 @@
 # include <pthread.h>
 #endif
 
+#ifdef __FreeBSD__
+#define	pthread_self()	getpid()
+#endif
+
 IGT_TEST_DESCRIPTION("Call drmGetMagic() and drmAuthMagic() and see if it behaves.");
 
 static bool
