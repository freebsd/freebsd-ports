--- connectivity/source/drivers/file/makefile.mk.orig	Wed Jun 12 01:12:42 2002
+++ connectivity/source/drivers/file/makefile.mk	Wed Jun 12 01:12:44 2002
@@ -112,7 +112,7 @@
 	$(SLO)$/fanalyzer.obj			\
 	$(SLO)$/fcomp.obj
 
-.IF "$(OS)"=="MACOSX"||"$(OS)"=="FREEBSD"
+.IF "$(OS)"=="MACOSX"
 #SHL1VERSIONMAP=$(TARGET).$(DLLPOSTFIX).map
 .ELSE      
 #SHL1VERSIONMAP=$(TARGET).map
