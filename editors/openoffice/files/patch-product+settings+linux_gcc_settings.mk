--- ../product/settings/linux_gcc_settings.mk.orig	Wed May 29 00:18:46 2002
+++ ../product/settings/linux_gcc_settings.mk	Wed May 29 00:19:04 2002
@@ -3,9 +3,8 @@
 OS=LINUX
 PLATFORM=linux
 PS=/
-CC=gcc
-LINK=gcc
-LIB=gcc
+LINK=$(CC)
+LIB=$(CC)
 ECHO=@echo
 MKDIR=mkdir -p
 CAT=cat
