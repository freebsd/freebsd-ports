--- ../connectivity/source/drivers/jdbc/makefile.mk.orig	Sat Mar  2 20:54:27 2002
+++ ../connectivity/source/drivers/jdbc/makefile.mk	Sat Mar  2 20:54:52 2002
@@ -111,7 +111,7 @@
 		$(SLO)$/tools.obj
 		
 
-.IF "$(OS)"=="MACOSX"
+.IF "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
 #SHL1VERSIONMAP=$(JDBC_TARGET).$(DLLPOSTFIX).map
 .ELSE      
 SHL1VERSIONMAP=$(JDBC_TARGET).map
