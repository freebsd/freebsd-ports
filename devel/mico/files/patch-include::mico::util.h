--- include/mico/util.h.orig	Wed Nov 24 07:25:44 2004
+++ include/mico/util.h	Wed Nov 24 07:25:29 2004
@@ -24,6 +24,10 @@
 #ifndef __mico_util_h__
 #define __mico_util_h__
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
+
 #include <CORBA.h>
 #ifdef HAVE_ANSI_CPLUSPLUS_HEADERS
 #include <iostream>
@@ -205,7 +209,11 @@
 #endif
 
 #ifndef HAVE_GETHOSTNAME_PROTO
+#if (defined(__FreeBSD__) && __FreeBSD_version < 500000)
+extern "C" int gethostname (char *, int);
+#else
 extern "C" int gethostname (char *, size_t);
+#endif
 #endif
 
 #ifndef HAVE_FINITE_PROTO
