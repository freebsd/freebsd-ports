--- ../sax/util/makefile.mk.old	Sun Mar  3 01:33:10 2002
+++ ../sax/util/makefile.mk	Sun Mar  3 01:33:03 2002
@@ -82,7 +82,9 @@
 			$(EXPAT3RDLIB)
 
 SHL1LIBS=		$(SLB)$/expatwrap.lib 
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP=		$(SOLARENV)$/src$/component.map
+.ENDIF
 SHL1DEF=		$(MISC)$/$(SHL1TARGET).def
 DEF1NAME=		$(SHL1TARGET)
 
