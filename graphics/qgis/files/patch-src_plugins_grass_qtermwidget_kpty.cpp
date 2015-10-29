--- src/plugins/grass/qtermwidget/kpty.cpp.orig	2015-10-23 12:10:38 UTC
+++ src/plugins/grass/qtermwidget/kpty.cpp
@@ -30,6 +30,7 @@
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #define HAVE_LOGIN
 #define HAVE_LIBUTIL_H
+#define HAVE_UTEMPTER
 #endif
 
 #ifdef __sgi
