--- ../connectivity/source/drivers/mozab/mozillasrc/makefile.mk.orig	Tue Apr 23 20:47:57 2002
+++ ../connectivity/source/drivers/mozab/mozillasrc/makefile.mk	Tue Apr 23 20:50:30 2002
@@ -144,7 +144,7 @@
 	    -I$(MOZ_INC)$/embed_base -I$(MOZ_INC)$/mozldap 
 CDEFS+=	    -DMOZILLA_CLIENT \
             -DOSTYPE=\"Linux2.2.14-5\" -DOJI
-.IF "$(OS)" == "LINUX"
+.IF "$(OS)" == "LINUX" || "$(OS)" == "FREEBSD"
 CFLAGS +=   -fPIC -g
 CFLAGSCXX += \
             -fno-rtti -Wall -Wconversion -Wpointer-arith \
