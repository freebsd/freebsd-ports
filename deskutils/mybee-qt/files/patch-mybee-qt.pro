--- mybee-qt.pro.orig	2025-01-23 11:34:32 UTC
+++ mybee-qt.pro
@@ -1,8 +1,8 @@ TEMPLATE = subdirs
 TEMPLATE = subdirs
-SUBDIRS = libssh freerdp2 vnc src
+SUBDIRS = src
 
 #CONFIG += ordered
-src.depends = libssh freerdp2 vnc
+#src.depends = libssh freerdp2 vnc
 
 DISTFILES += \
     APP_VERSION \
