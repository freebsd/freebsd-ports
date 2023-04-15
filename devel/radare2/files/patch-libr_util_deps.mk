--- libr/util/deps.mk.orig	2023-04-15 14:08:46 UTC
+++ libr/util/deps.mk
@@ -21,7 +21,7 @@ endif
 endif
 
 # FreeBSD 10.0 ships with backtrace(3) in -lexecinfo
-ifeq (${BUILD_OS},freebsd)
+ifeq (${HOST_OS},freebsd)
   ifneq ($(shell expr "`uname -r`" : '[0-9]\.'), 2)
     LDFLAGS+=-lexecinfo
   endif
@@ -42,4 +42,3 @@ LDFLAGS+=-lm
 LINK+=-lm
 endif
 endif
-
