do not need -ldl

http://qa.openoffice.org/issues/show_bug.cgi?id=27043
--- ../setup2/mow/source/loader/makefile.mk~	Tue Mar  9 21:04:35 2004
+++ ../setup2/mow/source/loader/makefile.mk	Mon Mar 29 11:10:50 2004
@@ -92,7 +92,11 @@
 LINK=gcc
 LINKFLAGS=
 LINKFLAGSAPP=
+.IF "$(OS)"=="FREEBSD"
+STDLIB= -lX11 -lc -lm
+.ELSE
 STDLIB= -lX11 -ldl -lc -lm
+.ENDIF          # "$(OS)"=="FREEBSD"
 .ENDIF          # "$(OS)$(COMID)"=="GCC"
 
 OBJFILES= $(OBJ)$/loader.obj
