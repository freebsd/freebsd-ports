--- ../extensions/source/scanner/makefile.mk.orig	Mon Jun  2 04:37:00 2003
+++ ../extensions/source/scanner/makefile.mk	Mon Jun  2 04:37:03 2003
@@ -135,7 +135,9 @@
 	$(GOODIESLIB)		
 
 .IF "$(GUI)"=="UNX"
+.IF "$(OS)"!="FREEBSD"
 SHL1STDLIBS+=$(SVTOOLLIB) -ldl
+.ENDIF
 .ENDIF
 
 SHL1DEF=$(MISC)$/$(SHL1TARGET).def
