--- common/tty/terminals.c.orig	2009-09-30 11:30:08.000000000 +0200
+++ common/tty/terminals.c	2011-10-09 02:58:53.000000000 +0200
@@ -31,7 +31,10 @@
 #ifndef WIN32
 
 /* First defined some macro to identify easily some systems */
-#if defined (__FreeBSD__) || defined (__NetBSD__)
+#if defined (__FreeBSD__) \
+ || defined (__OpenBSD__) \
+ || defined (__NetBSD__)  \
+ || defined (__DragonFly__) 
 #   define FREEBSD
 #endif
 #if defined (__alpha__) && defined (__osf__)
@@ -260,7 +263,9 @@
 #ifndef NLDLY
 #define NLDLY 0
 #define CRDLY 0
+#ifndef TABDLY
 #define TABDLY 0
+#endif
 #define BSDLY 0
 #define VTDLY 0
 #define FFDLY 0
