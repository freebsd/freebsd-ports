--- src/unx_net.cc.orig	2009-10-19 12:14:58.000000000 +0900
+++ src/unx_net.cc	2011-07-29 02:18:56.000000000 +0900
@@ -27,7 +27,7 @@
 #include <sys/ioctl.h>
 
 // -AJA- 2005/04/01: Yet another work-around for the huge pile of shit called C++
-#ifndef MACOSX
+#ifdef __linux__
 #define ntohl  ntohl_CRUD
 #define ntohs  ntohs_CRUD
 #define htonl  htonl_CRUD
@@ -36,7 +36,7 @@
 
 #include <arpa/inet.h>
 
-#ifdef MACOSX
+#ifndef __linux__
 #include <net/if.h>
 #else
 #include <linux/netdevice.h> 
