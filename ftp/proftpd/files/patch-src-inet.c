--- src/inet.c.orig	2010-04-08 16:31:54.398256052 +0200
+++ src/inet.c	2010-04-08 16:33:21.513206951 +0200
@@ -226,7 +226,8 @@
 
 #if defined(SOLARIS2) || defined(FREEBSD2) || defined(FREEBSD3) || \
     defined(FREEBSD4) || defined(FREEBSD5) || defined(FREEBSD6) || \
-    defined(FREEBSD7) || defined(__OpenBSD__) || defined(__NetBSD__) || \
+    defined(FREEBSD7) || defined(FREEBSD8) || defined(FREEBSD9) || \
+    defined(__OpenBSD__) || defined(__NetBSD__) || \
     defined(DARWIN6) || defined(DARWIN7) || defined(DARWIN8) || defined(DARWIN9) || defined(DARWIN10) || \
     defined(SCO3) || defined(CYGWIN) || defined(SYSV4_2MP) || \
     defined(SYSV5SCO_SV6) || defined(SYSV5UNIXWARE7)
@@ -244,7 +245,8 @@
 
 #if defined(SOLARIS2) || defined(FREEBSD2) || defined(FREEBSD3) || \
     defined(FREEBSD4) || defined(FREEBSD5) || defined(FREEBSD6) || \
-    defined(FREEBSD7) || defined(__OpenBSD__) || defined(__NetBSD__) || \
+    defined(FREEBSD7) || defined(FREEBSD8) || defined(FREEBSD9) || \
+    defined(__OpenBSD__) || defined(__NetBSD__) || \
     defined(DARWIN6) || defined(DARWIN7) || defined(DARWIN8) || defined(DARWIN9) || defined(DARWIN10) || \
     defined(SCO3) || defined(CYGWIN) || defined(SYSV4_2MP) || \
     defined(SYSV5SCO_SV6) || defined(SYSV5UNIXWARE7)
