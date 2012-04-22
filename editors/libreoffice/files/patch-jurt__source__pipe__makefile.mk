--- ./jurt/source/pipe/makefile.mk.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./jurt/source/pipe/makefile.mk	2012-04-16 14:24:48.000000000 +0200
@@ -51,6 +51,8 @@
 
 SLOFILES = $(SHL1OBJS)
 
+LINKFLAGS += -fPIC
+
 .IF "$(SOLAR_JAVA)" == ""
 nothing .PHONY :
 .END
