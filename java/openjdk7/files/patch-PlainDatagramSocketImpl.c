
# HG changeset patch
# User kurt
# Date 1359762569 18000
# Node ID bfa676f5b5db6a9c1c0e158eb40856c1b7f5f258
# Parent c721254e908da6aea0879f3d0e715003ff675525
- Fix MulticastSocket.setInterface() for BSD. Report and fix from Oliver
  Lehmann on bsd-port list.

--- jdk/src/solaris/native/java/net/PlainDatagramSocketImpl.c	Fri Jan 25 11:40:12 2013 -0500
+++ jdk/src/solaris/native/java/net/PlainDatagramSocketImpl.c	Fri Feb 01 18:49:29 2013 -0500
@@ -1358,7 +1358,7 @@ static void setMulticastInterface(JNIEnv
          * value is an InetAddress.
          */
 #ifdef AF_INET6
-#if defined(__solaris__) || defined(MACOSX)
+#if defined(__solaris__) || defined(_ALLBSD_SOURCE)
         if (ipv6_available()) {
             mcast_set_if_by_addr_v6(env, this, fd, value);
         } else {
@@ -1381,7 +1381,7 @@ static void setMulticastInterface(JNIEnv
          * value is a NetworkInterface.
          */
 #ifdef AF_INET6
-#if defined(__solaris__) || defined(MACOSX)
+#if defined(__solaris__) || defined(_ALLBSD_SOURCE)
         if (ipv6_available()) {
             mcast_set_if_by_if_v6(env, this, fd, value);
         } else {
@@ -1464,7 +1464,7 @@ static void setMulticastLoopbackMode(JNI
 static void setMulticastLoopbackMode(JNIEnv *env, jobject this, int fd,
                                   jint opt, jobject value) {
 #ifdef AF_INET6
-#if defined(__solaris__) || defined(MACOSX)
+#if defined(__solaris__) || defined(_ALLBSD_SOURCE)
     if (ipv6_available()) {
         mcast_set_loop_v6(env, this, fd, value);
     } else {
@@ -2038,7 +2038,7 @@ Java_java_net_PlainDatagramSocketImpl_se
     }
     /* setsockopt to be correct ttl */
 #ifdef AF_INET6
-#if defined(__solaris__) || defined(MACOSX)
+#if defined(__solaris__) || defined(_ALLBSD_SOURCE)
     if (ipv6_available()) {
         setHopLimit(env, fd, ttl);
     } else {
