--- ../sal/util/makefile.mk.orig	Tue Mar  5 21:36:23 2002
+++ ../sal/util/makefile.mk	Tue Mar  5 21:36:44 2002
@@ -113,7 +113,9 @@
 SHL1TARGET= $(TARGET)
 SHL1IMPLIB= i$(TARGET)
 
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP=	$(TARGET).map
+.ENDIF
 
 .IF "$(GUI)"=="WNT"
 .IF "$(COM)"!="GCC"
