--- mybee-qt.pro.orig	2025-02-16 18:06:21 UTC
+++ mybee-qt.pro
@@ -1,11 +1,10 @@ TEMPLATE = subdirs
 TEMPLATE = subdirs
-SUBDIRS = zlib-ng libjpeg-turbo libssh freerdp2 vnc src
+SUBDIRS = src
 
 #CONFIG += ordered
 libssh.depends = zlib-ng
 freerdp2.depends = zlib-ng libjpeg-turbo
 vnc.depends = zlib-ng libjpeg-turbo
-src.depends = libssh freerdp2 vnc
 
 DISTFILES += \
     APP_VERSION \
