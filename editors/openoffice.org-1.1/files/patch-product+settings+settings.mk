--- ../product/settings/settings.mk.orig	Wed May 29 00:16:16 2002
+++ ../product/settings/settings.mk	Wed May 29 00:18:00 2002
@@ -83,9 +83,8 @@
 
 OS=SOLARIS
 PS=/
-CC=CC
-LINK=CC
-LIB=CC
+LINK=$(CC)
+LIB=$(CC)
 ECHO=@echo
 MKDIR=mkdir -p
 CAT=cat
@@ -136,9 +135,8 @@
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
