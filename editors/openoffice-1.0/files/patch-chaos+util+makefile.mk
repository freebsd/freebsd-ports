--- chaos/util/makefile.mk.orig	Wed Jun 12 01:16:35 2002
+++ chaos/util/makefile.mk	Wed Jun 12 01:16:47 2002
@@ -100,7 +100,7 @@
 
 SHL1TARGET=	cnt$(UPD)$(DLLPOSTFIX)
 SHL1IMPLIB=	i$(TARGET)
-.IF "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
+.IF "$(OS)"=="MACOSX"
 #SHL1VERSIONMAP=	exports.$(DLLPOSTFIX).map
 .ELSE
 SHL1VERSIONMAP=	exports.map
