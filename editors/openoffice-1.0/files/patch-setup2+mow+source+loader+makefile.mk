--- setup2/mow/source/loader/makefile.mk.orig	Sun Mar  3 01:45:18 2002
+++ setup2/mow/source/loader/makefile.mk	Sun Mar  3 01:45:22 2002
@@ -85,7 +85,7 @@
 APP1NOSAL=TRUE
 APP1TARGET= $(TARGET)
 APP1OBJS=  $(OBJFILES)
-APP1STDLIBS= $(SVUNZIPLIB) $(LOADERLIB)
+APP1STDLIBS= $(SVUNZIPLIB) $(LOADERLIB) -lX11
 
 .ENDIF			# "$(OS)"=="MACOSX"
 
