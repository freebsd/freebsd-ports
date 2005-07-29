--- connectivity/source/drivers/jdbc/makefile.mk.orig	Wed Jun 12 00:57:12 2002
+++ connectivity/source/drivers/jdbc/makefile.mk	Wed Jun 12 00:57:21 2002
@@ -111,7 +111,7 @@
 		$(SLO)$/tools.obj
 		
 
-.IF "$(OS)"=="MACOSX"||"$(OS)"=="FREEBSD"
+.IF "$(OS)"=="MACOSX"
 #SHL1VERSIONMAP=$(JDBC_TARGET).$(DLLPOSTFIX).map
 .ELSE      
 SHL1VERSIONMAP=$(JDBC_TARGET).map
