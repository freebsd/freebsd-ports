--- ../desktop/util/makefile.mk.orig	Fri Feb 14 14:43:59 2003
+++ ../desktop/util/makefile.mk	Wed Mar  5 20:54:04 2003
@@ -102,7 +102,7 @@
 
 # --- Linken der Applikation ---------------------------------------
 
-.IF "$(OS)" == "LINUX"
+.IF "$(OS)" == "LINUX" || "$(OS)" == "FREEBSD"
 # #74158# linux needs sal/vos/tools at end of link list, solaris needs it first,
 # winXX is handled like solaris for now
 APP1_STDPRE=
@@ -139,7 +139,7 @@
 .ENDIF
 
 .IF "$(GUI)" == "UNX"
-.IF "$(OS)" == "LINUX"
+.IF "$(OS)" == "LINUX" || "$(OS)" == "FREEBSD"
 APP1STDLIBS+= -lXext -lSM -lICE
 .ENDIF
 .ENDIF
