--- ../setup2/mow/source/loader/makefile.mk.orig	Fri Feb 14 15:32:23 2003
+++ ../setup2/mow/source/loader/makefile.mk	Wed Mar  5 20:28:12 2003
@@ -95,7 +95,11 @@
 
 APP1TARGET=	$(TARGET)
 APP1OBJS=	$(OBJFILES)
+.IF "$(OS)"=="FREEBSD"
+APP1STDLIBS=$(SVUNZIPLIB) $(LOADERLIB) -lX11
+.ELSE
 APP1STDLIBS=$(SVUNZIPLIB) $(LOADERLIB) -ldl
+.ENDIF
 
 .ENDIF			# "$(OS)"=="MACOSX"
 
