--- desktop/util/makefile.mk.orig	Sun Jul 21 00:04:35 2002
+++ desktop/util/makefile.mk	Sun Jul 21 00:04:38 2002
@@ -81,7 +81,7 @@
 
 # --- Linken der Applikation ---------------------------------------
 
-.IF "$(OS)" == "LINUX"
+.IF "$(OS)" == "LINUX" || "$(OS)" == "FREEBSD"
 # #74158# linux needs sal/vos/tools at end of link list, solaris needs it first,
 # winXX is handled like solaris for now
 APP1_STDPRE=
@@ -111,7 +111,7 @@
 	$(SALHELPERLIB)
 
 .IF "$(GUI)" == "UNX"
-.IF "$(OS)" == "LINUX"
+.IF "$(OS)" == "LINUX" || "$(OS)" == "FREEBSD"
 
 APP1STDLIBS+= -lXext -lSM -lICE
 
