--- ../connectivity/source/drivers/file/makefile.mk.orig	Sat Mar  2 20:47:37 2002
+++ ../connectivity/source/drivers/file/makefile.mk	Sat Mar  2 20:48:04 2002
@@ -112,7 +112,7 @@
 	$(SLO)$/fanalyzer.obj			\
 	$(SLO)$/fcomp.obj
 
-.IF "$(OS)"=="MACOSX"
+.IF "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
 #SHL1VERSIONMAP=$(TARGET).$(DLLPOSTFIX).map
 .ELSE      
 #SHL1VERSIONMAP=$(TARGET).map
