--- libr/util/deps.mk.orig	2026-03-19 11:46:07 UTC
+++ libr/util/deps.mk
@@ -21,7 +21,7 @@ endif
 endif
 
 # FreeBSD 10.0 ships with backtrace(3) in -lexecinfo
-ifeq (${BUILD_OS},freebsd)
+ifeq (${HOST_OS},freebsd)
   ifneq ($(shell expr "`uname -r`" : '[0-9]\.'), 2)
     LDFLAGS+=-lexecinfo
   endif
@@ -42,7 +42,6 @@ endif
 LINK+=-lm
 endif
 endif
-
 ifeq (${OSTYPE},aix)
 LINK+=-pthread
 endif
