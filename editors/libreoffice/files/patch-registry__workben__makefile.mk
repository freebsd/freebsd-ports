--- ./registry/workben/makefile.mk.orig	2012-07-27 08:37:04.000000000 -0400
+++ ./registry/workben/makefile.mk	2012-08-28 19:38:00.000000000 -0400
@@ -63,8 +63,8 @@
 APP2RPATH=NONE
 .IF "$(GUI)"=="UNX" && "$(OS)"!="MACOSX"
 
-.IF "$(OS)"=="LINUX"
-APP2LINKFLAGS=-Wl,-rpath,\''$$ORIGIN:$$ORIGIN/../lib'\'
+.IF "$(OS)"=="LINUX" || "$(OS)"=="FREEBSD"
+APP2LINKFLAGS=-Wl,-z,origin,-rpath,\''$$ORIGIN:$$ORIGIN/../lib'\'
 .ENDIF
 
 .IF "$(OS)"=="SOLARIS"
