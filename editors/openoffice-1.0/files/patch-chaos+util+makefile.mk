--- ../chaos/util/makefile.mk.orig	Sat Mar  2 18:09:33 2002
+++ ../chaos/util/makefile.mk	Sat Mar  2 18:09:18 2002
@@ -100,7 +100,7 @@
 
 SHL1TARGET=	cnt$(UPD)$(DLLPOSTFIX)
 SHL1IMPLIB=	i$(TARGET)
-.IF "$(OS)"=="MACOSX"
+.IF "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
 #SHL1VERSIONMAP=	exports.$(DLLPOSTFIX).map
 .ELSE
 SHL1VERSIONMAP=	exports.map
