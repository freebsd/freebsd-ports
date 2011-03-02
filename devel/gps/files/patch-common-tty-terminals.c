--- common/tty/terminals.c.orig	2010-12-04 03:57:46 +0000
+++ common/tty/terminals.c
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
