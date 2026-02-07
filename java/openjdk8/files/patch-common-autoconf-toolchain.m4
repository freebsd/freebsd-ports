--- common/autoconf/toolchain.m4.orig	2014-11-08 19:52:00.000000000 -0800
+++ common/autoconf/toolchain.m4	2014-11-08 19:52:15.000000000 -0800
@@ -811,7 +811,7 @@
     fi
 
     if test "`uname -s`" = "FreeBSD"; then
-      PACKAGE_PATH=/usr/local
+      PACKAGE_PATH=%%LOCALBASE%%
     fi
 
     if test "`uname -s`" = "NetBSD"; then
