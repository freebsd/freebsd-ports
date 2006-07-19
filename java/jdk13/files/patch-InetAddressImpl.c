$FreeBSD$

--- ../src/solaris/native/java/net/InetAddressImpl.c.orig	Wed Jul 19 01:28:19 2006
+++ ../src/solaris/native/java/net/InetAddressImpl.c	Wed Jul 19 10:59:54 2006
@@ -26,9 +26,14 @@
 #include "java_net_InetAddressImpl.h"
 
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <sys/param.h>
+#endif
+
+#if (defined(__FreeBSD__) && (__FreeBSD_version < 601103 || \
+    (__FreeBSD_version >= 700000 && __FreeBSD_version < 700016))) || \
+    defined(__NetBSD__) || defined(__OpenBSD__)
 /* reentrant BIND includes --billh */
 
-#include <sys/param.h>
 #include <port_before.h>
 #include <port_after.h>
 
@@ -100,7 +105,9 @@ Java_java_net_InetAddressImpl_getLocalHo
 	char buf2[HENT_BUF_SIZE];
 	int h_error=0;
 
-#ifdef __GLIBC__
+#if defined(__GLIBC__) || \
+    (defined(__FreeBSD__) && (__FreeBSD_version >= 700016 || \
+    (__FreeBSD_version < 700000 && __FreeBSD_version >= 601103)))
 	gethostbyname_r(hostname, &res, buf, sizeof(buf), &hp, &h_error);
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 	hp = __j_gethostbyname_r(hostname, &res, buf, sizeof(buf), &h_error);
@@ -108,7 +115,9 @@ Java_java_net_InetAddressImpl_getLocalHo
 	hp = gethostbyname_r(hostname, &res, buf, sizeof(buf), &h_error);
 #endif
 	if (hp) {
-#ifdef __GLIBC__
+#if defined(__GLIBC__) || \
+    (defined(__FreeBSD__) && (__FreeBSD_version >= 700016 || \
+    (__FreeBSD_version < 700000 && __FreeBSD_version >= 601103)))
 	    gethostbyaddr_r(hp->h_addr, hp->h_length, AF_INET,
 			    &res2, buf2, sizeof(buf2), &hp, &h_error);
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
@@ -195,7 +204,9 @@ Java_java_net_InetAddressImpl_lookupAllH
     hostname = JNU_GetStringPlatformChars(env, host, JNI_FALSE);
 
     /* Try once, with our static buffer. */
-#ifdef __GLIBC__
+#if defined(__GLIBC__) || \
+    (defined(__FreeBSD__) && (__FreeBSD_version >= 700016 || \
+    (__FreeBSD_version < 700000 && __FreeBSD_version >= 601103)))
     gethostbyname_r(hostname, &res, buf, sizeof(buf), &hp, &h_error);
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     hp = __j_gethostbyname_r(hostname, &res, buf, sizeof(buf), &h_error);
@@ -210,7 +221,9 @@ Java_java_net_InetAddressImpl_lookupAllH
      */
     if (hp == NULL && errno == ERANGE) {
 	if ((tmp = (char*)malloc(BIG_HENT_BUF_SIZE))) {
-#ifdef __GLIBC__
+#if defined(__GLIBC__) || \
+    (defined(__FreeBSD__) && (__FreeBSD_version >= 700016 || \
+    (__FreeBSD_version < 700000 && __FreeBSD_version >= 601103)))
 	    gethostbyname_r(hostname, &res, tmp, BIG_HENT_BUF_SIZE,
 			    &hp, &h_error);
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
@@ -293,7 +306,9 @@ Java_java_net_InetAddressImpl_getHostByA
      * 
      */
     addr = htonl(addr);
-#ifdef __GLIBC__
+#if defined(__GLIBC__) || \
+    (defined(__FreeBSD__) && (__FreeBSD_version >= 700016 || \
+    (__FreeBSD_version < 700000 && __FreeBSD_version >= 601103)))
     gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET, &hent,
 		    buf, sizeof(buf), &hp, &h_error);
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
@@ -310,7 +325,9 @@ Java_java_net_InetAddressImpl_getHostByA
      */
     if (hp == NULL && errno == ERANGE) {
 	if ((tmp = (char*)malloc(BIG_HENT_BUF_SIZE))) {
-#ifdef __GLIBC__
+#if defined(__GLIBC__) || \
+    (defined(__FreeBSD__) && (__FreeBSD_version >= 700016 || \
+    (__FreeBSD_version < 700000 && __FreeBSD_version >= 601103)))
 	    gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET,
 			    &hent, tmp, BIG_HENT_BUF_SIZE, &hp, &h_error);
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
@@ -338,7 +355,9 @@ Java_java_net_InetAddressImpl_getHostByA
 
 /* =============================== */
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if (defined(__FreeBSD__) && (__FreeBSD_version < 601103 || \
+    (__FreeBSD_version >= 700000 && __FreeBSD_version < 700016))) || \
+    defined(__NetBSD__) || defined(__OpenBSD__)
 
 #if defined(LIBC_SCCS) && !defined(lint)
 static const char rcsid[] = "$Id: gethostent_r.c,v 8.5 2000/07/11 05:46:35 vixie Exp $";
