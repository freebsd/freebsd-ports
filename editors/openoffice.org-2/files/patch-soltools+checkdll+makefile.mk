--- ../soltools/checkdll/makefile.mk.orig	Tue Mar 11 14:21:02 2003
+++ ../soltools/checkdll/makefile.mk	Tue Mar 11 14:21:30 2003
@@ -80,7 +80,9 @@
 APP1TARGET	= 	checkdll
 APP1OBJS	=	$(OBJ)$/checkdll.obj
 DEPOBJFILES	=	$(APP1OBJS) 
+.IF "$(OS)"!="FREEBSD"
 STDLIB += -ldl
+.ENDIF
 .IF "$(OS)"=="NETBSD"
 APP1STDLIBS	+= -Wl,--whole-archive -lgcc -Wl,--no-whole-archive
 .ENDIF
