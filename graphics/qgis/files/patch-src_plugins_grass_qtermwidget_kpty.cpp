--- src/plugins/grass/qtermwidget/kpty.cpp.orig	2016-10-21 12:14:02 UTC
+++ src/plugins/grass/qtermwidget/kpty.cpp
@@ -28,6 +28,8 @@
 
 
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#define HAVE_UTEMPTER
+#define HAVE_UTMPX
 #define HAVE_LOGIN
 #define HAVE_LIBUTIL_H
 #endif
