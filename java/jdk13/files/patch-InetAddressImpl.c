$FreeBSD$

--- ../src/solaris/native/java/net/InetAddressImpl.c.orig	Tue Jun  6 14:38:22 2006
+++ ../src/solaris/native/java/net/InetAddressImpl.c	Tue Jun  6 15:13:29 2006
@@ -26,9 +26,13 @@
 #include "java_net_InetAddressImpl.h"
 
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <sys/param.h>
+#endif
+
+#if (defined(__FreeBSD__) && __FreeBSD_version < 700016) || \
+    defined(__NetBSD__) || defined(__OpenBSD__)
 /* reentrant BIND includes --billh */
 
-#include <sys/param.h>
 #include <port_before.h>
 #include <port_after.h>
 
@@ -100,7 +104,7 @@ Java_java_net_InetAddressImpl_getLocalHo
 	char buf2[HENT_BUF_SIZE];
 	int h_error=0;
 
-#ifdef __GLIBC__
+#if defined(__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700016)
 	gethostbyname_r(hostname, &res, buf, sizeof(buf), &hp, &h_error);
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 	hp = __j_gethostbyname_r(hostname, &res, buf, sizeof(buf), &h_error);
@@ -108,7 +112,7 @@ Java_java_net_InetAddressImpl_getLocalHo
 	hp = gethostbyname_r(hostname, &res, buf, sizeof(buf), &h_error);
 #endif
 	if (hp) {
-#ifdef __GLIBC__
+#if defined(__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700016)
 	    gethostbyaddr_r(hp->h_addr, hp->h_length, AF_INET,
 			    &res2, buf2, sizeof(buf2), &hp, &h_error);
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
@@ -195,7 +199,7 @@ Java_java_net_InetAddressImpl_lookupAllH
     hostname = JNU_GetStringPlatformChars(env, host, JNI_FALSE);
 
     /* Try once, with our static buffer. */
-#ifdef __GLIBC__
+#if defined(__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700016)
     gethostbyname_r(hostname, &res, buf, sizeof(buf), &hp, &h_error);
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     hp = __j_gethostbyname_r(hostname, &res, buf, sizeof(buf), &h_error);
@@ -210,7 +214,7 @@ Java_java_net_InetAddressImpl_lookupAllH
      */
     if (hp == NULL && errno == ERANGE) {
 	if ((tmp = (char*)malloc(BIG_HENT_BUF_SIZE))) {
-#ifdef __GLIBC__
+#if defined(__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700016)
 	    gethostbyname_r(hostname, &res, tmp, BIG_HENT_BUF_SIZE,
 			    &hp, &h_error);
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
@@ -293,7 +297,7 @@ Java_java_net_InetAddressImpl_getHostByA
      * 
      */
     addr = htonl(addr);
-#ifdef __GLIBC__
+#if defined(__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700016)
     gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET, &hent,
 		    buf, sizeof(buf), &hp, &h_error);
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
@@ -310,7 +314,7 @@ Java_java_net_InetAddressImpl_getHostByA
      */
     if (hp == NULL && errno == ERANGE) {
 	if ((tmp = (char*)malloc(BIG_HENT_BUF_SIZE))) {
-#ifdef __GLIBC__
+#if defined(__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700016)
 	    gethostbyaddr_r((char *)&addr, sizeof(addr), AF_INET,
 			    &hent, tmp, BIG_HENT_BUF_SIZE, &hp, &h_error);
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
@@ -338,7 +342,8 @@ Java_java_net_InetAddressImpl_getHostByA
 
 /* =============================== */
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if (defined(__FreeBSD__) && __FreeBSD_version < 700016) || \
+    defined(__NetBSD__) || defined(__OpenBSD__)
 
 #if defined(LIBC_SCCS) && !defined(lint)
 static const char rcsid[] = "$Id: gethostent_r.c,v 8.5 2000/07/11 05:46:35 vixie Exp $";
