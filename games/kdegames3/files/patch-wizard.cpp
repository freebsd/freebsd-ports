--- ksirtet/lib/wizard.cpp.old	Mon Apr 22 10:51:55 2002
+++ ksirtet/lib/wizard.cpp	Mon Apr 22 10:52:14 2002
@@ -24,7 +24,7 @@
 #ifdef __bsdi__
 #define IPPORT_USERRESERVED IPPORT_DYNAMIC
 #endif
-#if defined(__NetBSD__) || defined(__sgi)
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__sgi)
 #define IPPORT_USERRESERVED IPPORT_RESERVED
 #endif
 #define MIN_USER_PORT (unsigned short int)IPPORT_USERRESERVED
