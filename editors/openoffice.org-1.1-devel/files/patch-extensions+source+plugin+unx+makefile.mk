--- ../extensions/source/plugin/unx/makefile.mk.orig	Mon Oct 21 08:48:31 2002
+++ ../extensions/source/plugin/unx/makefile.mk	Mon Oct 21 08:48:59 2002
@@ -91,7 +91,11 @@
 .IF "$(OS)"=="SOLARIS" || "$(OS)"=="SCO" || "$(OS)"=="HPUX"
 APP1STDLIBS+=-lXm -lXt -lX11 -ldl
 .ELSE
+.IF "$(OS)"=="FREEBSD"
+APP1STDLIBS+=-lXaw -lXt -lX11
+.ELSE
 APP1STDLIBS+=-lXaw -lXt -lX11 -ldl
+.ENDIF
 .ENDIF
 
 APP1DEF=	$(MISC)$/$(TARGET).def
