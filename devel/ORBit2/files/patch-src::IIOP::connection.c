$NetBSD: patch-ag,v 1.6 2001/05/21 19:59:04 rh Exp $

--- src/IIOP/connection.c.orig	Sun May 13 09:07:46 2001
+++ src/IIOP/connection.c
@@ -1,4 +1,7 @@
 #include "config.h"
+#include <sys/types.h>
+#include <sys/param.h>
+#include <stdio.h>
 #if defined (__hpux) && ! defined (_XOPEN_SOURCE_EXTENDED)
 #   define _XOPEN_SOURCE_EXTENDED 1
 #   define WE_DEFINED_XOPEN_SOURCE_EXTENDED 1
@@ -13,7 +16,6 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <errno.h>
-#include <sys/types.h>
 #include <fcntl.h>
 #include <sys/socket.h>
 #include <sys/un.h>
@@ -32,7 +34,7 @@
 #include <signal.h>
 #include <syslog.h>
 
-#if defined(HAVE_TCPD_H) && defined(HAVE_HOSTS_ACCESS)
+#if defined(HAVE_TCPD_H)
 #include <tcpd.h>
 #endif
 
@@ -80,7 +82,7 @@
 GIOPConnectionList giop_connection_list;
 static GSList *iiop_unix_socket_list = NULL;
 
-#if defined(HAVE_HOSTS_ACCESS) && defined (HAVE_TCPD_H)
+#if defined (HAVE_TCPD_H)
 static const char *argv0_val = NULL;
 #endif
 
@@ -104,7 +106,7 @@
   struct sigaction mypipe;
   g_assert(sizeof(GIOPMessageHeader) == 12);
 
-#if defined(HAVE_HOSTS_ACCESS) && defined (HAVE_TCPD_H)
+#if defined (HAVE_TCPD_H)
   argv0_val = g_strdup(g_basename(argv0)); /* For TCP wrappers */
 #endif
 
@@ -1007,7 +1009,7 @@
  */
 int allow_severity = LOG_INFO, deny_severity = LOG_NOTICE;
 
-#if defined(HAVE_HOSTS_ACCESS) && defined(HAVE_TCPD_H)
+#if defined(HAVE_TCPD_H)
 DEFINE_LOCK(tcp_wrappers_usage);
 
 #endif
@@ -1033,7 +1035,7 @@
 
   newfd = accept(GIOP_CONNECTION_GET_FD(connection), &sock, &n);
 
-#if defined(HAVE_HOSTS_ACCESS) && defined(HAVE_TCPD_H)
+#if defined(HAVE_TCPD_H)
   /* tcp wrappers access checking */
   switch(IIOP_CONNECTION(connection)->icnxtype) {
   case IIOP_IPV4:
