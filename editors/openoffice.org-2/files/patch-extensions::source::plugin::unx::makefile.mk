--- ../extensions/source/plugin/unx/makefile.mk.orig	Mon Mar 11 01:34:07 2002
+++ ../extensions/source/plugin/unx/makefile.mk	Mon Mar 11 10:21:01 2002
@@ -91,7 +91,11 @@
 .IF "$(OS)"=="SOLARIS" || "$(OS)"=="SCO" || "$(OS)"=="HPUX"
 APP1STDLIBS+=-lXm -lXt -lX11 -ldl
 .ELSE
+IF "$(OS)"=="FREEBSD"
+APP1STDLIBS+=-lXaw -lXt -lX11
+.ELSE
 APP1STDLIBS+=-lXaw -lXt -lX11 -ldl
+.ENDIF
 .ENDIF
 
 APP1DEF=	$(MISC)$/$(TARGET).def
