--- ../util/makefile.mk.orig	Sat Mar  2 21:17:20 2002
+++ ../inet/util/makefile.mk	Sat Mar  2 21:17:42 2002
@@ -116,7 +116,7 @@
 
 SHL1TARGET=		$(TARGET)$(UPD)$(DLLPOSTFIX)
 SHL1IMPLIB=		$(TARGET)
-.IF "$(OS)"=="MACOSX"
+.IF "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
 #SHL1VERSIONMAP=	$(TARGET).$(DLLPOSTFIX).map
 .ELSE
 SHL1VERSIONMAP=	$(TARGET).map
